#ifndef QMLDIALPAD_H
#define QMLDIALPAD_H

#include <QtDeclarative>
#include <QtGui>

class QmlDialPad : public QWidget
{
  Q_OBJECT
public:
  explicit QmlDialPad(QWidget *parent = 0);
signals:
  void Login(QString);
  void Disconnect();
public slots:
  void callLogin(QString id);
  void callDisconnect();
private:
  QDeclarativeView* declarativeView;
};

#endif // QMLDIALPAD_H
