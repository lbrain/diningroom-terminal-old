#ifndef GUI_H
#define GUI_H

#include <QtGui>
#include "OrderArray.h"

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
public slots:
  void ListLoaded(OrderArray array);
  void SetFirstPage();
  void SetSecondPage();
private:
  Ui::GUI *ui;
};

#endif // GUI_H
