#include <QtGui>
#include "CORE.h"

int main(int argc, char** argv) {
  QApplication app(argc, argv);

  CORE core;
  core.Connect("root", "localhost", "openaccess", "diningroom");
  core.Check();
  return app.exec();
}
