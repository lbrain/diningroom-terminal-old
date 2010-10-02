#ifndef QMLDIALPAD_H
#define QMLDIALPAD_H

#include <QDeclarativeView>

class QmlDialPad : public QDeclarativeView
{
  Q_OBJECT
public:
  explicit QmlDialPad(QWidget *parent = 0);

signals:
  void Login();
public slots:

};

#endif // QMLDIALPAD_H
