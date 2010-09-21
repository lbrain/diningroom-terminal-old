#ifndef WORKPAGE_H
#define WORKPAGE_H

#include <QtGui>
#include "Order.h"

namespace Ui {
    class WorkPage;
}

class WorkPage : public QWidget
{
  Q_OBJECT
public:
  explicit WorkPage(QWidget *parent = 0);
  ~WorkPage();
signals:
  void Disconnect();
  void ConfirmOrder(Order);
  void DiscardOrder(Order);
public slots:
  void ListLoaded(Order, QString);
  void Confirm();
  void Discard();
private:
  void Init();
private:
  Order order;
  QString orderText;
  Ui::WorkPage *ui;
};

#endif // WORKPAGE_H
