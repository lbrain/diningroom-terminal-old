#include "MenuPage.h"
#include "ui_MenuPage.h"

MenuPage::MenuPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPage)
{
    ui->setupUi(this);
    Init();
}

void MenuPage::Init() {
  connect(ui->page1, SIGNAL(Order(Menu)), ui->page2, SLOT(SetOrder(Menu)));
  connect(ui->page1, SIGNAL(Order(Menu)), this, SLOT(SetConfirmPage()));

  connect(ui->page1, SIGNAL(Logout()), this, SIGNAL(Logout()));

  connect(ui->page2, SIGNAL(PrevSubpage()), this, SLOT(SetMenuPage()));

  connect(ui->page2, SIGNAL(SaveOrder(Menu)), this, SIGNAL(SaveOrder(Menu)));
}

MenuPage::~MenuPage()
{
    delete ui;
}

void MenuPage::SetMenuPage() {
  ui->pager->setCurrentIndex(0);
}

void MenuPage::SetConfirmPage() {
  ui->pager->setCurrentIndex(1);
}

void MenuPage::SetData(Employee userinfo, Menu menu) {
  SetMenuPage();
  ui->userInfoLabel->setText(userinfo.GetFormatted());
  ui->page1->SetMenu(menu);
}
