#ifndef MENUSUBPAGETWO_H
#define MENUSUBPAGETWO_H

#include <QWidget>
#include "Menu.h"

namespace Ui {
    class MenuSubpageTwo;
}

class MenuSubpageTwo : public QWidget
{
  Q_OBJECT
private:
  void Init();
public:
  MenuSubpageTwo(QWidget *parent = 0);
  ~MenuSubpageTwo();
public slots:
  void SetOrder(Menu _order);
  void SaveOrderClicked();
signals:
  void PrevSubpage();
  void SaveOrder(Menu _order);
private:
  Ui::MenuSubpageTwo *ui;
};

#endif // MENUSUBPAGETWO_H
