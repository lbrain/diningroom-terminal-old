#include "Employee.h"

Employee::Employee(QString _id,
                   QString _surname,
                   QString _name,
                   QString _patronymic) {
  SetId(_id);
  SetSurname(_surname);
  SetName(_name);
  SetPatronymic(_patronymic);
}

Employee::Employee() {
  Employee("", "", "", "");
}

void Employee::SetId(QString _id) {
  id = _id;
}

void Employee::SetSurname(QString _surname) {
  surname = _surname;
}

void Employee::SetName(QString _name) {
  name = _name;
}

void Employee::SetPatronymic(QString _patronymic) {
  patronymic = _patronymic;
}

QString Employee::GetId() {
  return id;
}

QString Employee::GetSurname() {
  return surname;
}

QString Employee::GetName() {
  return name;
}

QString Employee::GetPatronymic() {
  return patronymic;
}

QString Employee::GetFormatted(QString format) {
  format.replace("%i", id);
  format.replace("%s", surname);
  format.replace("%n", name);
  format.replace("%p", patronymic);
  return format;
}
