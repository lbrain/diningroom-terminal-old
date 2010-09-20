#ifndef DIALPAGE_H
#define DIALPAGE_H

#include <QtGui>

namespace Ui {
    class DialPage;
}

class DialPage : public QWidget
{
  Q_OBJECT
public:
  explicit DialPage(QWidget *parent = 0);
  void Init();
  void InitSignalSlotConnections();
  ~DialPage();

private:
  Ui::DialPage *ui;
signals:
  void Login(QString id);
  void Disconnect();
public slots:
  void Clear();
  void EnterClicked();
private slots:
  void buttonPressed(const QString& buttonname);
};

#endif // DIALPAGE_H
