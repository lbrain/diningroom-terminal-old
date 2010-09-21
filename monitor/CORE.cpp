#include "CORE.h"

const QString CONNECTIONNAME = "DBMONITORCONNECTION";
const QString DBDRIVER = "QMYSQL";

CORE::CORE(QObject *parent) : QObject(parent) {
  Init();
}

void CORE::Init() {
  db_connected = false;
}

void CORE::Connect(QString name,
                   QString host,
                   QString password,
                   QString database) {
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
  QString query_string =
      "SELECT date, employee_id, surname, name, patronymic, SUM(count*price) "
      "FROM "
      "        (SELECT o.id, o.date, o.dish_id, o.count, o.employee_id, o.status, e.surname, e.name, e.patronymic, d.price "
      "         FROM orders o, dishes d, employees e "
      "        WHERE o.dish_id = d.id AND status = 'NA' AND e.id = employee_id "
      "        ORDER BY o.date) s "
      "GROUP BY date, employee_id "
      "ORDER BY date ";

  OrderArray orderArray;
  SqlTable table = GetFromDB(query_string, 6);
  for (int i = 0; i < table.size(); i++) {
    Order newOrder = Order(table[i][0].toString(),
                           table[i][1].toString(),
                           table[i][2].toString(),
                           table[i][3].toString(),
                           table[i][4].toString(),
                           table[i][5].toString());
    orderArray.push_back(newOrder);
  }
  emit ListLoaded(orderArray);
}

SqlTable CORE::GetFromDB(QString query_string, int fieldsCount) {
  if (!db_connected) {
    qDebug() << "GetFromDB:";
    qDebug() << " Connect to database first!";
    return SqlTable();
  }
  QSqlQuery query(db);
//  QString query_string = "SELECT " + fields[0];
//  for (int i = 1; i < fields.size(); i++) {
//    query_string += ", " + fields[i];
//  }
//  query_string += " FROM " + table + " ";
//  if (!condition.isEmpty()) {
//    query_string += "WHERE " + condition;
//  }

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
