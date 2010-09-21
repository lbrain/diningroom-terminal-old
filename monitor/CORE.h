#ifndef CORE_H
#define CORE_H

#include <QtGui>
#include <QtSql>
#include "OrderArray.h"

typedef QVector< QVector<QVariant> >  SqlTable;

class CORE : public QObject {
  Q_OBJECT
public:
  CORE(QObject *parent = 0);

signals:
  void Connected();
  void Disconnected();
  void ListLoaded(OrderArray);
public slots:
  void Connect(
      QString database,
      QString name,
      QString host,
      QString password);
  void Disconnect();
  void Check();
private:
  void Init();
  SqlTable GetFromDB(QString query_string, int fieldsCount);
private:
  QString db_name;
  QString db_username;
  QString db_host;
  bool db_connected;
  QSqlDatabase db;
};

#endif // CORE_H
