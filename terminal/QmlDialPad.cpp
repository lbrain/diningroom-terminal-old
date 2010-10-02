#include "QmlDialPad.h"

QmlDialPad::QmlDialPad(QWidget *parent) :
    QDeclarativeView(parent)
{
  this->setSource(QUrl("/home/hasan/QtCreator_projects/myQMLapp/myQMLapp.qml"));
  this->setResizeMode(QDeclarativeView::SizeRootObjectToView);
}
