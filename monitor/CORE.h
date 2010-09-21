#ifndef CORE_H
#define CORE_H

#include <QtGui>
#include <QtSql>
#include "Order.h"

typedef QVector< QVector<QVariant> >  SqlTable;

class CORE : public QObject {
  Q_OBJECT
public:
  CORE(QObject *parent = 0);

signals:
  void Connected();
  void Disconnected();
  void ListLoaded(Order, QString);
  void StatusChanged();
public slots:
  void Connect(
      QString database,
      QString name,
      QString host,
      QString password);
  void Disconnect();
  void Check();
  void ConfirmOrder(Order order);
  void DiscardOrder(Order order);
private:
  void Init();
  SqlTable GetFromDB_ex(QString query_string, int fieldsCount);
  void SetOrderStatus(Order order, QString status);
private:
  QString db_name;
  QString db_username;
  QString db_host;
  bool db_connected;
  QSqlDatabase db;
};

#endif // CORE_H
