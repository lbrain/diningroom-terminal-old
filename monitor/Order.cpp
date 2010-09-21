#include "Order.h"

Order::Order() {
  Order("", "", "", "", "", "");
}

Order::Order(QString ndate,
             QString nemployee_id,
             QString nsurname,
             QString nname,
             QString npatronymic,
             QString nprice) {
  SetDate(ndate);
  SetEmployeeId(nemployee_id);
  SetSurname(nsurname);
  SetName(nname);
  SetPatronymic(npatronymic);
  SetPrice(nprice);
}

void Order::SetDate(QString ndate) {
  date = ndate;
}

void Order::SetEmployeeId(QString nemployee_id) {
  employee_id = nemployee_id;
}

void Order::SetSurname(QString nsurname) {
  surname = nsurname;
}

void Order::SetName(QString nname) {
  name = nname;
}

void Order::SetPatronymic(QString npatronymic) {
  patronymic = npatronymic;
}

void Order::SetPrice(QString nprice) {
  price = nprice;
}

QString Order::GetDate() {
  return date;
}

QString Order::GetEmployeeId() {
  return employee_id;
}

QString Order::GetSurname() {
  return surname;
}

QString Order::GetName() {
  return name;
}

QString Order::GetPatronymic() {
  return patronymic;
}

QString Order::GetPrice() {
  return price;
}

QString Order::operator [](int index) {
  if (index < 0 || index >= COLUMNSCOUNT)
    return QString();
  switch (index) {
  case 0: {
      return GetDate();
      break;
    }
  case 1: {
      return GetEmployeeId();
      break;
    }
  case 2: {
      return GetSurname();
      break;
    }
  case 3: {
      return GetName();
      break;
    }
  case 4: {
      return GetPatronymic();
      break;
    }
  case 5: {
      return GetPrice();
      break;
    }
  }
  return QString();
}
