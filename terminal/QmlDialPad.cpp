#include "QmlDialPad.h"

QmlDialPad::QmlDialPad(QWidget *parent) :
    QWidget(parent) {
  declarativeView = new QDeclarativeView();
  declarativeView->setSource(QUrl("qrc:qmlDialPad/qmlDialPad.qml"));
  declarativeView->setResizeMode(QDeclarativeView::SizeRootObjectToView);
  QHBoxLayout* layout = new QHBoxLayout(this);
  layout->addWidget(declarativeView);

  QDeclarativeContext* context = declarativeView->rootContext();
  context->setContextProperty("CLASS", this);
}

void QmlDialPad::callLogin(QString id) {
  emit Login(id);
}

void QmlDialPad::callDisconnect() {
  emit Disconnect();
}


