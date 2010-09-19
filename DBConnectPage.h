#ifndef DBCONNECTPAGE_H
#define DBCONNECTPAGE_H

#include <QtGui>

namespace Ui {
    class DBConnectPage;
}

class DBConnectPage : public QWidget
{
    Q_OBJECT

public:
  explicit DBConnectPage(QWidget *parent = 0);
  ~DBConnectPage();
private:
  Ui::DBConnectPage *ui;
  void Init();
private slots:
  void GenerateConnectSignal();
signals:
  void Connect(QString database,
               QString name,
               QString host,
               QString password);
  void Quit();
};

#endif // DBCONNECTPAGE_H
