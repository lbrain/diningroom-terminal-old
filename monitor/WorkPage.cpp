#include "WorkPage.h"
#include "ui_WorkPage.h"

WorkPage::WorkPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkPage)
{
    ui->setupUi(this);
}

WorkPage::~WorkPage()
{
    delete ui;
}
