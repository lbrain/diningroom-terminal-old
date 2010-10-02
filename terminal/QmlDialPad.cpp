#include "QmlDialPad.h"

QmlDialPad::QmlDialPad(QWidget *parent) :
    QDeclarativeView(parent)
{
  this->setSource(QUrl("/home/hasan/QtCreator_projects/lbrain-diningroom-terminal/terminal/qmlDialPad/qmlDialPad.qml"));
  this->setResizeMode(QDeclarativeView::SizeRootObjectToView);
}
