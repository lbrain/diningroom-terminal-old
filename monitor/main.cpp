#include <QtGui>
#include "CORE.h"
#include "DBConnectPage.h"
#include "GUI.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  GUI* gui = new GUI();
  gui->show();

  CORE* core = new CORE();


  QObject::connect(gui, SIGNAL(Connect(QString,QString,QString,QString)),
                   core, SLOT(Connect(QString,QString,QString,QString)));

  QObject::connect(gui, SIGNAL(Quit()),
                   &app, SLOT(quit()));

  QObject::connect(core, SIGNAL(Connected()),
                   gui, SLOT(SetSecondPage()));

  QObject::connect(core, SIGNAL(Disconnected()),
                   gui, SLOT(SetFirstPage()));

  return app.exec();
}
