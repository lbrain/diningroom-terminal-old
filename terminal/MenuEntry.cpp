#include "MenuEntry.h"

MenuEntry::MenuEntry(QString _id,
                     QString _name,
                     double  _price,
                     double  _remaining,
                     double  _count) {
  SetId(_id);
  SetName(_name);
  SetPrice(_price);
  SetRemaining(_remaining);
  SetCount(_count);
}

MenuEntry::MenuEntry() {
  MenuEntry("", "", 0.0, 0);
}

void MenuEntry::SetId(QString _id) {
  id = _id;
}

void MenuEntry::SetName(QString _name) {
  name = _name;
}

void MenuEntry::SetPrice(double _price) {
  price = _price;
}

void MenuEntry::SetCount(double _count) {
  count = _count;
}

void MenuEntry::SetRemaining(double _remaining) {
  remaining = _remaining;
}

void MenuEntry::IncCount(double _c) {
  count += _c;
}

void MenuEntry::DecCount(double _c) {
  count -= _c;
}

QString MenuEntry::GetId() const {
  return id;
}

QString MenuEntry::GetName() const {
  return name;
}

double MenuEntry::GetPrice() const {
  return price;
}

double MenuEntry::GetCount() const {
  return count;
}

double MenuEntry::GetRemaining() const {
  return remaining;
}

double MenuEntry::operator++ () {
  IncCount();
  return GetCount();
}

double MenuEntry::operator-- () {
  DecCount();
  return GetCount();
}

double MenuEntry::operator+= (double _c) {
  IncCount(_c);
  return GetCount();
}

double MenuEntry::operator-= (double _c) {
  DecCount(_c);
  return GetCount();
}

QVariant MenuEntry::GetByColumnNumber(int number) const {
  switch (number) {
  case 0: {
      return QVariant(GetId());
      break;
    }
  case 1: {
      return QVariant(GetName());
      break;
    }
  case 2: {
      return QVariant(GetPrice());
      break;
    }
  case 3: {
      return QVariant(GetCount());
      break;
    }
  case 4: {
    return QVariant(GetRemaining());
    break;
  }
  default: {
      return QVariant();
      break;
    }
  }
}
