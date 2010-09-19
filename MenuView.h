#ifndef MENUVIEW_H
#define MENUVIEW_H

#include <QtGui>
#include "MenuModel.h"
#include "Menu.h"

class MenuView : public QTableView {
  Q_OBJECT
public:
  MenuView(QWidget *parent = 0);
  MenuView(bool _readonly, QWidget *parent = 0);
signals:
  void Order(Menu _order);
  void TotalPrice(double _totalPrice);
public slots:
  void SetMenu(Menu _menu);
  //void SetMenu(Employee, Menu _menu);
  void AllowSelection(bool allow);
  void SetSelection(double addend, bool relative = true);
  void IncSelectionByHalf();
  void IncSelectionByOne();
  void IncSelectionByFive();
  void DecSelectionByHalf();
  void DecSelectionByOne();
  void DecSelectionByFive();
  void ZeroSelection();
  void ZeroAll();
  void EmitOrder();
  void EmitTotalPrice();
  void ResizeColumns();
private:
  MenuModel* model;
  bool readOnly;
  void Init(bool _readonly);
};

#endif // MENUVIEW_H
