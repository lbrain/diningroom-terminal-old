#ifndef GUI_H
#define GUI_H

#include <QtGui>
#include "Menu.h"
#include "Employee.h"

namespace Ui {
    class GUI;
}

class GUI : public QWidget
{
  Q_OBJECT
public:
  GUI(QWidget *parent = 0);
  ~GUI();
private:
  Ui::GUI *ui;

private:
  void Init();
public slots:
  void SetDialPage();
  void SetMenuPage(Employee _userinfo, Menu _menu);
  void SetLastPage();
  void SetDBConnectPage();
signals:
  void Disconnect();
  void Connect(QString database,
               QString name,
               QString host,
               QString password);
  void Login(QString _id);
  void Logout();
  void SaveOrder(Menu _order);
  void Quit();
};

#endif // GUI_H
