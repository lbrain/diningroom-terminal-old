#ifndef MENUMODEL_H
#define MENUMODEL_H

#include <QtGui>
#include "Menu.h"
#include "Employee.h" //Удалить

class MenuModel : public QAbstractTableModel {
  Q_OBJECT
public:
  double GetTotalPrice();
  Menu GetOrder();
  MenuModel(QObject *parent = 0);
  MenuModel(bool _colored, QObject *parent = 0);
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  int columnCount(const QModelIndex &parent) const;
  QVariant headerData(int section,
                      Qt::Orientation orientation,
                      int role) const;
  QVariant data(const QModelIndex &index, int role) const;
  bool setData(const QModelIndex &index, const QVariant &value, int role);
  Qt::ItemFlags flags(const QModelIndex &index) const;
signals:
public slots:
  void SetMenu(Menu _menu);
  void SetMenu(Employee, Menu);
  void SetColored(bool x);
  void ZeroAll();
private:
  Menu menu;
  bool colored;
};

#endif // MENUMODEL_H
