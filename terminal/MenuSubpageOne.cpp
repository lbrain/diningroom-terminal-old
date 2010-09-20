#include "MenuSubpageOne.h"
#include "ui_MenuSubpageOne.h"

MenuSubpageOne::MenuSubpageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuSubpageOne)
{
    ui->setupUi(this);
    Init();
}

void MenuSubpageOne::Init() {
  connect(ui->buttonPlus5, SIGNAL(clicked()), ui->menuTable,    SLOT(IncSelectionByFive()));
  connect(ui->buttonPlus1, SIGNAL(clicked()), ui->menuTable,    SLOT(IncSelectionByOne()));
  connect(ui->buttonPlus05, SIGNAL(clicked()), ui->menuTable,   SLOT(IncSelectionByHalf()));
  connect(ui->buttonMinus5, SIGNAL(clicked()), ui->menuTable,  SLOT(DecSelectionByFive()));
  connect(ui->buttonMinus1, SIGNAL(clicked()), ui->menuTable,   SLOT(DecSelectionByOne()));
  connect(ui->buttonMinus05, SIGNAL(clicked()), ui->menuTable,   SLOT(DecSelectionByHalf()));
  connect(ui->buttonZero, SIGNAL(clicked()), ui->menuTable, SLOT(ZeroSelection()));
  connect(ui->buttonZeroAll, SIGNAL(clicked()), ui->menuTable, SLOT(ZeroAll()));

  connect(ui->menuTable, SIGNAL(TotalPrice(double)), this, SIGNAL(TotalPrice(double)));
  connect(ui->menuTable, SIGNAL(Order(Menu)), this, SIGNAL(Order(Menu)));
  connect(this, SIGNAL(TotalPrice(double)), this, SLOT(SetPrice(double)));

  connect(ui->logoutButton, SIGNAL(clicked()), this, SIGNAL(Logout()));
  connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(EmitOrder()));
}

MenuSubpageOne::~MenuSubpageOne()
{
    delete ui;
}

void MenuSubpageOne::SetMenu(Menu _menu) {
  ui->menuTable->SetMenu(_menu);
}

void MenuSubpageOne::SetMenu(Employee, Menu _menu) {
  SetMenu(_menu);
}

void MenuSubpageOne::EmitTotalPrice() {
  ui->menuTable->EmitTotalPrice();
}

void MenuSubpageOne::EmitOrder() {
  ui->menuTable->EmitOrder();
}

void MenuSubpageOne::SetPrice(double price) {
  ui->priceLabel->setText(QString("Total price: %1 p").arg(price));
}
