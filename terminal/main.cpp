#include <QtGui>
#include "CORE.h"
#include "GUI.h"
#include <QtDeclarative>

int main(int argc, char** argv) {
  QApplication app(argc, argv);
  CORE *core = new CORE();
  GUI* gui = new GUI();
  gui->showFullScreen();

  /*QDeclarativeView* view = new QDeclarativeView();
  view->setSource(QUrl("qrc:qmlDialPad/qmlDialPad.qml"));
  view->show();
  QDeclarativeContext* context = view->rootContext();
  context->setContextProperty("GUI", gui);*/

  QObject::connect(gui, SIGNAL(Login(QString)), core, SLOT(Login(QString)));
  QObject::connect(core, SIGNAL(LoginSuccess(Employee,Menu)), gui, SLOT(SetMenuPage(Employee,Menu)));
  QObject::connect(gui, SIGNAL(Logout()), core, SLOT(Unlogin()));
  QObject::connect(core, SIGNAL(UnloginSuccess()), gui, SLOT(SetDialPage()));
  QObject::connect(gui, SIGNAL(SaveOrder(Menu)), core, SLOT(SaveOrder(Menu)));
  QObject::connect(core, SIGNAL(OrderSaved()), gui, SLOT(SetLastPage()));

  QObject::connect(gui, SIGNAL(Disconnect()), core, SLOT(Disconnect()));
  QObject::connect(gui, SIGNAL(Connect(QString,QString,QString,QString)), core, SLOT(Connect(QString,QString,QString,QString)));

  QObject::connect(core, SIGNAL(Connected(QString,QString,QString)), gui, SLOT(SetDialPage()));
  QObject::connect(core, SIGNAL(Disconnected()), gui, SLOT(SetDBConnectPage()));

  QObject::connect(gui, SIGNAL(Quit()), core, SLOT(TryQuit()));
  QObject::connect(core, SIGNAL(DoQuit()), &app, SLOT(quit()));

  return app.exec();
}
