#include "QmlDialPad.h"

QmlDialPad::QmlDialPad(QWidget *parent) :
    QDeclarativeView(parent)
{
  this->setSource(QUrl::fromLocalFile("qrc:qmlDialPad/qmlDialPad.qml"));
  this->setResizeMode(QDeclarativeView::SizeRootObjectToView);
}
