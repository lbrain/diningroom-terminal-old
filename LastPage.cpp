#include "LastPage.h"
#include "ui_LastPage.h"

LastPage::LastPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LastPage)
{
    ui->setupUi(this);
    Init();
}

LastPage::~LastPage()
{
    delete ui;
}

void LastPage::Init() {
  connect(ui->logoutButton, SIGNAL(clicked()), this, SIGNAL(Logout()));
}
