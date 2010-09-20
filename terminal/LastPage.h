#ifndef LASTPAGE_H
#define LASTPAGE_H

#include <QWidget>

namespace Ui {
    class LastPage;
}

class LastPage : public QWidget
{
  Q_OBJECT
private:
  void Init();
public:
  LastPage(QWidget *parent = 0);
  ~LastPage();
signals:
  void Logout();
private:
  Ui::LastPage *ui;
};

#endif // LASTPAGE_H
