#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QString>

class Employee {
  QString id;
  QString surname;
  QString name;
  QString patronymic;
public:
    Employee();
    Employee(QString _id,
             QString _surname,
             QString _name,
             QString _patronymic);

    void SetId(QString _id);
    void SetSurname(QString _surname);
    void SetName(QString _name);
    void SetPatronymic(QString _patronymic);

    QString GetId();
    QString GetName();
    QString GetSurname();
    QString GetPatronymic();
    QString GetFormatted(QString format = "%i %s %n %p");
};

#endif // EMPLOYEE_H
