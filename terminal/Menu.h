#ifndef MENU_H
#define MENU_H

#include <QVector>
#include "MenuEntry.h"

class Menu : public QVector<MenuEntry> {
public:
  double GetTotalPrice();
  Menu GetOrder();
  void ZeroAll();
};

#endif // MENU_H
