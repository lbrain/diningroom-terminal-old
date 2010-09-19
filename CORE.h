#ifndef CORE_H
#define CORE_H

#include <QtGui>
#include <QtSql>
#include "Employee.h"
#include "Menu.h"

typedef QVector< QVector<QVariant> >  SqlTable;

class CORE : public QObject {
  Q_OBJECT
public:
  CORE();
private:
  void DbInit();
public slots:
  void Connect(QString _name,
               QString _username,
               QString _host,
               QString _password);
  void Disconnect();
  void TryQuit();
signals:
  void Connected(QString _name, QString _username, QString _host);
  void Disconnected();
  void DoQuit();
private:
  QString db_name;
  QString db_username;
  QString db_host;
  bool db_connected;
  QSqlDatabase db;

private:
  SqlTable sql_result;
public:
  SqlTable GetFromDB(QStringList fields, QString table, QString condition = "");

public slots:
  void Login(QString _id);
  void SaveOrder(Menu _order);
  void Unlogin();
signals:
  void LoginSuccess(Employee _employee, Menu _menuarray);
  void OrderSaved();
  void UnloginSuccess();
private:
  bool loginstate;
  Employee userinfo;
  Menu menuarray;
};

#endif // CORE_H
