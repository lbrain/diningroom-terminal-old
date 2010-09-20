#include "DBConnectPage.h"
#include "ui_DBConnectPage.h"

DBConnectPage::DBConnectPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DBConnectPage)
{
    ui->setupUi(this);
    Init();
}

DBConnectPage::~DBConnectPage()
{
    delete ui;
}

void DBConnectPage::Init() {
  connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(GenerateConnectSignal()));
  connect(ui->quitButton, SIGNAL(clicked()), this, SIGNAL(Quit()));
}

void DBConnectPage::GenerateConnectSignal() {
  emit Connect(ui->databaseField->text(),
               ui->loginField->text(),
               ui->hostField->text(),
               ui->passwordField->text());
  ui->passwordField->clear();
}
