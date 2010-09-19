#ifndef MENUSUBPAGEONE_H
#define MENUSUBPAGEONE_H

#include <QWidget>
#include "MenuView.h"
#include "Menu.h"
#include "Employee.h"

namespace Ui {
    class MenuSubpageOne;
}

class MenuSubpageOne : public QWidget
{
  Q_OBJECT
public:
  explicit MenuSubpageOne(QWidget *parent = 0);
  ~MenuSubpageOne();
private:
  Ui::MenuSubpageOne *ui;
private:
  void Init();
public slots:
  void EmitTotalPrice();
  void EmitOrder();
  void SetPrice(double price);
  void SetMenu(Menu _menu);
  void SetMenu(Employee, Menu _menu);
signals:
  void ToNextSubpage();
  void TotalPrice(double price);
  void Order(Menu order);
  void Logout();
};

#endif // MENUSUBPAGEONE_H
