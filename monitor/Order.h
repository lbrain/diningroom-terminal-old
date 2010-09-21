#ifndef ORDER_H
#define ORDER_H

const int COLUMNSCOUNT = 6;

#include <QtGui>

class Order {
public:
  Order();
  Order(QString ndate,
        QString nemployee_id,
        QString nsurname,
        QString nname,
        QString npatronymic,
        QString nprice);
  QString GetDate();
  QString GetEmployeeId();
  QString GetSurname();
  QString GetName();
  QString GetPatronymic();
  QString GetPrice();

  void SetDate(QString ndate);
  void SetEmployeeId(QString nemployee_id);
  void SetSurname(QString nsurname);
  void SetName(QString nname);
  void SetPatronymic(QString npatronymic);
  void SetPrice(QString nprice);

  QString operator[] (int index);
private:
  QString date;
  QString employee_id;
  QString surname;
  QString name;
  QString patronymic;
  QString price;
};

#endif // ORDER_H
