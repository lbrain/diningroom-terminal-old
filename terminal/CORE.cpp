#include "CORE.h"

const QString DBDRIVER = "QMYSQL";
const QString CONNECTIONNAME = "CONNECTION";
const QString EMPLOYEESTABLE = "employees";
const QString DISHTABLE = "dishes";
const QString ORDERSTABLE = "orders";
const QString EMPLOYEECONDITION = "deleted = 0";
const QString DISHCONDITION = "deleted = 0 AND remaining > 0";

CORE::CORE() {
  DbInit();
}

void CORE::DbInit() {
  db_connected = false;
}

void CORE::TryQuit() {
  if (!db_connected)
    emit DoQuit();
}

void CORE::Connect(
    QString name, QString username, QString host, QString password)
{
  if (db_connected)
    return;

  db = QSqlDatabase::addDatabase(DBDRIVER, CONNECTIONNAME);
  db.setUserName(username);
  db.setDatabaseName(name);
  db.setHostName(host);
  db.setPassword(password);
  db_connected = db.open();
  if (db_connected) {
    db_name = name;
    db_host = host;
    db_username = username;
    emit Connected(db_name, db_username, db_host);
    qDebug() << "Connected to database. Connection name: " << CONNECTIONNAME;
  }
}

void CORE::Disconnect() {
  if (loginstate) {
    Unlogin();
  }
  if (!db_connected && !loginstate)
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

SqlTable CORE::GetFromDB(QStringList fields, QString table, QString condition) {
  if (!db_connected || fields.size() == 0) {
    if (!db_connected) {
      qDebug() << "GetFromDB:";
      qDebug() << " Connect to database first!";
    }
    return SqlTable();
  }
  QSqlQuery query(db);
  QString query_string = "SELECT " + fields[0];
  for (int i = 1; i < fields.size(); i++) {
    query_string += ", " + fields[i];
  }
  query_string += " FROM " + table + " ";
  if (!condition.isEmpty()) {
    query_string += "WHERE " + condition;
  }

  if (!query.exec(query_string)) {
    return SqlTable();
  }

  SqlTable result;
  result.resize(query.size());
  for (int recordIndx = 0; recordIndx < query.size(); recordIndx++) {
    query.next();
    for (int fieldIndx = 0; fieldIndx < fields.size(); fieldIndx++) {
      result[recordIndx].push_back(query.value(fieldIndx));
    }
  }

  return result;
}

void CORE::Login(QString _id) {
  if (!db_connected) {
    qDebug() << "Login:";
    qDebug() << " Connect to database first!";
    return;
  }

  //Check user id
  SqlTable table = GetFromDB(QStringList()
                             << "id"
                             << "surname"
                             << "name"
                             << "patronymic",
                             EMPLOYEESTABLE,
                             "id = " + _id + " AND " + EMPLOYEECONDITION);
  if (table.size() == 0) {
    qDebug() << "No such employee";
    return;
  }

  loginstate = true;
  userinfo = Employee(table[0][0].toString(),
                      table[0][1].toString(),
                      table[0][2].toString(),
                      table[0][3].toString());

  //Load menu from database
  table = GetFromDB(QStringList()
                    << "id"
                    << "name"
                    << "price"
                    << "remaining",
                    DISHTABLE,
                    DISHCONDITION);
  menuarray.resize(table.size());
  for (int dishIndx = 0; dishIndx < table.size(); dishIndx++) {
    menuarray[dishIndx] = MenuEntry(table[dishIndx][0].toString(),
                                    table[dishIndx][1].toString(),
                                    table[dishIndx][2].toDouble(),
                                    table[dishIndx][3].toDouble());
  }

  for (int i = 0; i < menuarray.size(); i++) {
    MenuEntry e = menuarray[i];
    qDebug() << e.GetId() << e.GetName() << e.GetPrice() << ' ' << e.GetRemaining() << ' ' << e.GetCount();
  }

  emit LoginSuccess(userinfo, menuarray);
  qDebug() << "Login success: " << userinfo.GetFormatted();
}

void CORE::Unlogin() {
  if (!db_connected) {
    qDebug() << "Unlogin:";
    qDebug() << " Connect to database first!";
    return;
  }
  loginstate = false;
  userinfo = Employee();
  qDebug() << "Unlogin success";
  emit UnloginSuccess();
}

void CORE::SaveOrder(Menu _order) {
  if (!db_connected) {
    qDebug() << "SaveOrder:";
    qDebug() << " Connect to database first!";
    return;
  }

  Menu temp = _order;
  _order.clear();
  for (int i = 0; i < temp.size(); i++) {
    if (temp[i].GetCount() != 0) {
      _order.push_back(temp[i]);
    }
  }
  if (_order.size() == 0) {
    qDebug() << "Empty order!";
    return;
  }

  QString currentdate = QDateTime::currentDateTime().toString(Qt::ISODate);
  QString employee_id = userinfo.GetId();
  QVariant max = GetFromDB(QStringList() << "MAX(id)", ORDERSTABLE)[0][0];
  int maxid = -1;
  if (!max.isNull()) {
    maxid = max.toInt();
  }
  maxid++;

  QString sqlquery;
  for (int orderIndx = 0; orderIndx < _order.size(); orderIndx++) {
    int currentid = maxid + orderIndx;
    sqlquery += QString("(%1, \"%2\", %3, %4, %5, \"%6\")")
              .arg(currentid)
              .arg(currentdate)
              .arg(_order[orderIndx].GetId())
              .arg(_order[orderIndx].GetCount())
              .arg(employee_id)
              .arg("NA")+ ",";
  }

  sqlquery[sqlquery.size()-1] = ';';
  sqlquery = QString("INSERT INTO %1 VALUES " + sqlquery)
             .arg(ORDERSTABLE);
  qDebug() << sqlquery;
  QSqlQuery query(db);
  //Занесение с базу заказа
  if (!query.exec(sqlquery)) {
    qDebug() << query.lastError();
    return;
  }

  //Обновления счетчиков в базе
  for (int i = 0; i < _order.size(); i++) {
    qDebug() << _order[i].GetId() << _order[i].GetRemaining() - _order[i].GetCount();
    QString dish_id = _order[i].GetId();
    double new_remain = _order[i].GetRemaining() - _order[i].GetCount();
    sqlquery = QString("UPDATE %1 SET remaining = %2 WHERE id = %3")
        .arg(DISHTABLE)
        .arg(new_remain)
        .arg(dish_id);
    if (!query.exec(sqlquery)) {
      qDebug() << query.lastError();
      return;
    }
  }

  qDebug() << "OrderSaved";
  emit OrderSaved();
}
