#include "WorkPage.h"
#include "ui_WorkPage.h"

WorkPage::WorkPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WorkPage)
{
    ui->setupUi(this);
    Init();
}

WorkPage::~WorkPage()
{
    delete ui;
}

void WorkPage::ListLoaded(Order o, QString s) {
  order = o;
  orderText = s;

  ui->snpLabel->setText(order.GetEmployeeId() + " "
                        + order.GetName() + " "
                        + order.GetSurname() + " "
                        + order.GetPatronymic() + " "
                        + order.GetPrice());
  ui->orderText->setText(orderText);
}

void WorkPage::Init() {
  connect(ui->confirmButton, SIGNAL(clicked()),
          this, SLOT(Confirm()));
  connect(ui->discardButton, SIGNAL(clicked()),
          this, SLOT(Discard()));
  connect(ui->disconnectButton, SIGNAL(clicked()),
          this, SIGNAL(Disconnect()));
}

void WorkPage::Confirm() {
  emit ConfirmOrder(order);
}

void WorkPage::Discard() {
  emit DiscardOrder(order);
}
