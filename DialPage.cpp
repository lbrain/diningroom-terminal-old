#include "DialPage.h"
#include "ui_DialPage.h"

const QString BUTTONPREFIX = "btn";

DialPage::DialPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DialPage)
{
  ui->setupUi(this);
  Init();
  InitSignalSlotConnections();
}

DialPage::~DialPage() {
  delete ui;
}

void DialPage::Init() {
  connect(ui->btnEnter, SIGNAL(clicked()), this, SLOT(EnterClicked()));
  connect(ui->disconnectButton, SIGNAL(clicked()), this, SIGNAL(Disconnect()));
}

void DialPage::InitSignalSlotConnections() {
  QSignalMapper* signalMapper = new QSignalMapper(this);
  QList<QPushButton*> buttons = findChildren<QPushButton*>();

  foreach(QPushButton* button, buttons) {
    if (button->objectName() != "btnEnter") {
      connect(button, SIGNAL(clicked()), signalMapper, SLOT(map()));
      signalMapper->setMapping(button, button->objectName());
    }
  }

  connect(signalMapper, SIGNAL(mapped(const QString&)),
          SLOT(buttonPressed(const QString&)));
}

void DialPage::buttonPressed(const QString &buttonname) {
  QString command = buttonname;
  command.remove(0, BUTTONPREFIX.size());
  QString text = ui->idField->text();

  if (command.contains(QRegExp("^[0-9]$"))) {
    text += command;
  } else if (command == "Backspace") {
    text.remove(text.size()-1, 1);
  } else if (command == "Clear") {
    text.clear();
  }

  ui->idField->setText(text);
}

void DialPage::Clear() {
  ui->idField->clear();
}

void DialPage::EnterClicked() {
  if (ui->idField->text().isEmpty()) {
    return;
  }
  emit Login(ui->idField->text());
  Clear();
}
