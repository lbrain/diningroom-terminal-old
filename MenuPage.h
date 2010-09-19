#ifndef MENUPAGE_H
#define MENUPAGE_H

#include <QtGui>
#include "Menu.h"
#include "Employee.h"

namespace Ui {
    class MenuPage;
}

class MenuPage : public QWidget
{
  Q_OBJECT
private:
  void Init();
private slots:
  void SetMenuPage();
  void SetConfirmPage();
public slots:
  void SetData(Employee userinfo, Menu menu);
public:
  explicit MenuPage(QWidget *parent = 0);
  ~MenuPage();
signals:
  void Logout();
  void SaveOrder(Menu);
private:
  Ui::MenuPage *ui;
};

#endif // MENUPAGE_H
