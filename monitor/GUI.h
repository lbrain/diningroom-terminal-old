#ifndef GUI_H
#define GUI_H

#include <QtGui>
#include "Order.h"

namespace Ui {
    class GUI;
}

class GUI : public QWidget {
  Q_OBJECT
public:
  explicit GUI(QWidget *parent = 0);
  ~GUI();
private:
  void Init();
signals:
  void Connect(QString, QString, QString, QString);
  void Quit();
  void Check();
  void ConfirmOrder(Order);
  void DiscardOrder(Order);
  void Disconnect();
public slots:
  void ListLoaded(Order order, QString text);
  void SetFirstPage();
  void SetSecondPage();
  void SetBlankPage();
  void StatusChanged();
private:
  Ui::GUI *ui;
  QTimer* timer;
};

#endif // GUI_H
