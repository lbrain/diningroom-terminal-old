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

  connect(ui->work_page, SIGNAL(ConfirmOrder(Order)),
          this, SIGNAL(ConfirmOrder(Order)));
  connect(ui->work_page, SIGNAL(DiscardOrder(Order)),
          this, SIGNAL(DiscardOrder(Order)));
  connect(ui->work_page, SIGNAL(Disconnect()),
          this, SIGNAL(Disconnect()));

  timer = new QTimer(this);
  timer->setInterval(1000);
  timer->stop();

  connect(timer, SIGNAL(timeout()),
          this, SIGNAL(Check()));
}

GUI::~GUI()
{
    delete ui;
}

void GUI::ListLoaded(Order order, QString text) {
  ui->work_page->ListLoaded(order, text);
  SetSecondPage();
}

void GUI::SetFirstPage() {
  ui->pager->setCurrentIndex(0);
  timer->stop();
}

void GUI::SetSecondPage() {
  ui->pager->setCurrentIndex(1);
  timer->stop();
}

void GUI::SetBlankPage() {
  ui->pager->setCurrentIndex(2);
  timer->start();
}

void GUI::StatusChanged() {
  SetBlankPage();
  emit Check();
}
