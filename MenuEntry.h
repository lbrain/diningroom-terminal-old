#ifndef MENUENTRY_H
#define MENUENTRY_H

#include <QtGui>

class MenuEntry {
  QString id;
  QString name;
  double  price;
  double  remaining;
  double  count;
public:
    MenuEntry();
    MenuEntry(QString _id,
              QString _name,
              double  _price,
              double  _remaining,
              double  _count = 0);

    void SetId(QString _id);
    void SetName(QString _name);
    void SetPrice(double _price);
    void SetCount(double _count);
    void SetRemaining(double _remaining);
    void IncCount(double _c = 1);
    void DecCount(double _c = 1);

    QString GetId() const;
    QString GetName() const;
    double  GetPrice() const;
    double  GetCount() const;
    double  GetRemaining() const;
    QVariant GetByColumnNumber(int number) const;

public:
    double operator++ ();
    double operator-- ();
    double operator+= (double _c);
    double operator-= (double _c);
};

#endif // MENUENTRY_H
