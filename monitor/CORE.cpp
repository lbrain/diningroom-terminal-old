#include "CORE.h"

const QString CONNECTIONNAME = "DBMONITORCONNECTION";
const QString DBDRIVER = "QMYSQL";
const QString EMPLOYEESTABLE = "employees";
const QString DISHTABLE = "dishes";
const QString ORDERSTABLE = "orders";

CORE::CORE(QObject *parent) : QObject(parent) {
  Init();
}

void CORE::Init() {
  db_connected = false;
}

void CORE::Connect(
    QString database,
    QString name,
    QString host,
    QString password) {
  if (db_connected)
    return;

  db = QSqlDatabase::addDatabase(DBDRIVER, CONNECTIONNAME);
  db.setUserName(name);
  db.setDatabaseName(database);
  db.setHostName(host);
  db.setPassword(password);
  db_connected = db.open();
  if (db_connected) {
    db_name = name;
    db_host = host;
    db_username = name;
    emit Connected();
    qDebug() << "Connected to database. Connection name: " << CONNECTIONNAME;
  }
}

void CORE::Disconnect() {
  if (!db_connected)
    return;

  db.close();
  db.removeDatabase(CONNECTIONNAME);
  db_connected = false;
  db_name = "";
  db_host = "";
  db_username = "";
  emit Disconnected();
  qDebug() << "Disconnected from database.";
}

void CORE::Check() {
  if (!db_connected)
    return;
  QString query_string =
      "SELECT date, employee_id, surname, name, patronymic, SUM(count*price) "
      "FROM "
      "        (SELECT \'>>> \', o.date, o.dish_id, o.count, o.employee_id, o.status, e.surname, e.name, e.patronymic, d.price "
      "         FROM orders o, dishes d, employees e "
      "        WHERE o.dish_id = d.id AND status = \'NA\' AND e.id = employee_id "
      "        ORDER BY o.date) s "
      "WHERE date = (SELECT MIN(date) FROM orders WHERE status = \'NA\') "
      "GROUP BY date, employee_id ";

  SqlTable orderTable = GetFromDB_ex(query_string, 6);

  Order newOrder;
  if (orderTable.size() == 0) {
    qDebug() << "Empty list";
    return;
  }
  newOrder = Order(orderTable[0][0].toString(),
                   orderTable[0][1].toString(),
                   orderTable[0][2].toString(),
                   orderTable[0][3].toString(),
                   orderTable[0][4].toString(),
                   orderTable[0][5].toString());

  query_string = QString(
      "SELECT "
      "     '>>> ', o.date, d.name, o.count, d.price "
      "FROM "
      "     orders o, dishes d "
      "WHERE "
      "     o.dish_id = d.id AND o.employee_id = %1 AND date = \'%2\' "
      "ORDER BY "
      "     date, employee_id").arg(newOrder.GetEmployeeId()).arg(newOrder.GetDate());
  qDebug() << query_string;
  SqlTable menuTable = GetFromDB_ex(query_string, 5);

  if (menuTable.size() == 0) {
    return;
  }

  QString tableToText;
  for (int i = 0; i < menuTable.size(); i++) {
    tableToText += menuTable[i][0].toString() + " " +
                   menuTable[i][1].toString() + " " +
                   menuTable[i][2].toString() + " ======== " +
                   menuTable[i][3].toString() + " ******** " +
                   menuTable[i][4].toString();
    tableToText += '\n';
  }

  emit ListLoaded(newOrder, tableToText);
}

SqlTable CORE::GetFromDB_ex(QString query_string, int fieldsCount) {
  if (!db_connected) {
    qDebug() << "GetFromDB:";
    qDebug() << " Connect to database first!";
    return SqlTable();
  }
  QSqlQuery query(db);

  if (!query.exec(query_string)) {
    return SqlTable();
  }

  SqlTable result;
  result.resize(query.size());
  for (int recordIndx = 0; recordIndx < query.size(); recordIndx++) {
    query.next();
    for (int fieldIndx = 0; fieldIndx < fieldsCount; fieldIndx++) {
      result[recordIndx].push_back(query.value(fieldIndx));
    }
  }

  return result;
}

void CORE::ConfirmOrder(Order order) {
  SetOrderStatus(order, "A");
}

void CORE::DiscardOrder(Order order) {
  SetOrderStatus(order, "D");
}

void CORE::SetOrderStatus(Order order, QString status) {
  QSqlQuery query(db);
  QString query_string = QString(
      "UPDATE %1 SET status = \'%2\' WHERE date = \'%3\' AND employee_id = %4")
      .arg(ORDERSTABLE)
      .arg(status)
      .arg(order.GetDate())
      .arg(order.GetEmployeeId());
  if (!query.exec(query_string)) {
    qDebug() << query.lastError();
    return;
  }

  if (status == "D") {
    query_string = QString(
        "UPDATE orders o, dishes d "
        "SET d.remaining = o.count+d.remaining "
        "WHERE o.date = \'%1\' AND o.employee_id = %2 AND o.dish_id = d.id")
        .arg(order.GetDate())
        .arg(order.GetEmployeeId());
    qDebug() << query_string;
    if (!query.exec(query_string)) {
      qDebug() << query.lastError();
      return;
    }
  }
  emit StatusChanged();
}
