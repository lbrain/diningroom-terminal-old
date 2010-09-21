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
                   gui, SLOT(SetBlankPage()));

  QObject::connect(core, SIGNAL(Disconnected()),
                   gui, SLOT(SetFirstPage()));

  QObject::connect(core, SIGNAL(Connected()),
                   core, SLOT(Check()));

  QObject::connect(core, SIGNAL(ListLoaded(Order,QString)),
                   gui, SLOT(ListLoaded(Order,QString)));

  QObject::connect(gui, SIGNAL(ConfirmOrder(Order)),
                   core, SLOT(ConfirmOrder(Order)));

  QObject::connect(gui, SIGNAL(DiscardOrder(Order)),
                   core, SLOT(DiscardOrder(Order)));

  QObject::connect(gui, SIGNAL(Disconnect()),
                   core, SLOT(Disconnect()));

  QObject::connect(core, SIGNAL(StatusChanged()),
                   gui, SLOT(StatusChanged()));

  QObject::connect(gui, SIGNAL(Check()),
                   core, SLOT(Check()));

  return app.exec();
}
