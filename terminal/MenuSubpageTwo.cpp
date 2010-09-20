#include "MenuSubpageTwo.h"
#include "ui_MenuSubpageTwo.h"

MenuSubpageTwo::MenuSubpageTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuSubpageTwo)
{
    ui->setupUi(this);
    Init();
}

MenuSubpageTwo::~MenuSubpageTwo()
{
    delete ui;
}

void MenuSubpageTwo::Init() {
  ui->orderTable->AllowSelection(false);
  connect(ui->confirmButton, SIGNAL(clicked()), ui->orderTable, SLOT(EmitOrder()));
  connect(ui->orderTable, SIGNAL(Order(Menu)), this, SIGNAL(SaveOrder(Menu)));
  connect(ui->prevButton, SIGNAL(clicked()), this, SIGNAL(PrevSubpage()));
}

void MenuSubpageTwo::SetOrder(Menu _order) {
  ui->orderTable->SetMenu(_order);
  double price = _order.GetTotalPrice();
  ui->priceLabel->setText(QString("Total price: %1 p").arg(price));
}

void MenuSubpageTwo::SaveOrderClicked() {
  ui->orderTable->EmitOrder();
}
