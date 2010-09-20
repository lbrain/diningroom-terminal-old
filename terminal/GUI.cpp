#include "GUI.h"
#include "ui_GUI.h"

GUI::GUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI)
{
  ui->setupUi(this);
  Init();
}

GUI::~GUI()
{
  delete ui;
}

void GUI::SetDialPage() {
  ui->pager->setCurrentIndex(0);
}

void GUI::SetMenuPage(Employee _userinfo, Menu _menu) {
  ui->page2->SetData(_userinfo, _menu);
  ui->pager->setCurrentIndex(1);
}

void GUI::SetLastPage() {
  ui->pager->setCurrentIndex(2);
}

void GUI::Init() {
  ui->pager->setCurrentIndex(3);

  connect(ui->page1, SIGNAL(Login(QString)), this, SIGNAL(Login(QString)));
  connect(ui->page2, SIGNAL(Logout()), this, SIGNAL(Logout()));
  connect(ui->page2, SIGNAL(SaveOrder(Menu)), this, SIGNAL(SaveOrder(Menu)));
  connect(ui->page3, SIGNAL(Logout()), this, SIGNAL(Logout()));

  connect(ui->page1, SIGNAL(Disconnect()), this, SIGNAL(Disconnect()));
  connect(ui->page4, SIGNAL(Connect(QString,QString,QString,QString)),
          this, SIGNAL(Connect(QString,QString,QString,QString)));
  connect(ui->page4, SIGNAL(Quit()), this, SIGNAL(Quit()));
}

void GUI::SetDBConnectPage() {
  ui->pager->setCurrentIndex(3);
}
