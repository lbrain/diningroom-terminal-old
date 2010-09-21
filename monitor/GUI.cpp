#include "GUI.h"
#include "ui_GUI.h"

GUI::GUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GUI)
{
    ui->setupUi(this);
    Init();
}

void GUI::Init() {
  connect(ui->db_connect_page, SIGNAL(Connect(QString,QString,QString,QString)),
          this, SIGNAL(Connect(QString,QString,QString,QString)));
  connect(ui->db_connect_page, SIGNAL(Quit()),
          this, SIGNAL(Quit()));
}

GUI::~GUI()
{
    delete ui;
}

void GUI::ListLoaded(OrderArray array) {

}

void GUI::SetFirstPage() {
  ui->pager->setCurrentIndex(0);
}

void GUI::SetSecondPage() {
  ui->pager->setCurrentIndex(1);
}
