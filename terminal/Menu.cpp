#include "Menu.h"

double Menu::GetTotalPrice() {
  double total = 0.0;
  for (int i = 0; i < this->size(); i++) {
    MenuEntry current = this->operator [](i);
    total += current.GetCount() * current.GetPrice();
  }
  return total;
}

Menu Menu::GetOrder() {
  Menu order;
  for (int i = 0; i < this->size(); i++) {
    if (this->at(i).GetCount() > 0)
      order.push_back(this->at(i));
  }
  return order;
}

void Menu::ZeroAll() {
  for (int i = 0; i < this->size(); i++) {
    this->operator [](i).SetCount(0);
  }
}
