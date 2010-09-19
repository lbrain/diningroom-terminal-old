#include "MenuView.h"

const int COLUMNCOUNT = 4;
const int NAME_COLUMN = 0;
const int PRICE_COLUMN = 1;
const int COUNT_COLUMN = 2;
const int REMAIN_COLUMN = 3;

void MenuView::Init(bool _readonly) {
  model = new MenuModel();
  setModel(model);
  setSelectionBehavior(QAbstractItemView::SelectRows);
  AllowSelection(!_readonly);

  /*Дичайший костыль, исправить при первой возможности*/
  QTimer* timer = new QTimer(this);
  timer->setInterval(200);
  timer->start();
  connect(timer, SIGNAL(timeout()), this, SLOT(ResizeColumns()));
}

void MenuView::ResizeColumns() {
  int wgtWidth = this->width();
  int tinyColumnWidth = wgtWidth / 6;
  for (int i = 0; i < COLUMNCOUNT; i++) {
    int w = tinyColumnWidth;
    if (i == 0)
      w *= 2;
    setColumnWidth(i, w);
  }
}

MenuView::MenuView(QWidget *parent) :
    QTableView(parent) {
  Init(false);
}

MenuView::MenuView(bool _readonly, QWidget *parent) :
    QTableView(parent)
{
  Init(_readonly);
  connect(this, SIGNAL(activated(QModelIndex)), SLOT(ResizeColumns()));
}

void MenuView::SetMenu(Menu _menu) {
  model->SetMenu(_menu);
}

/*void MenuView::SetMenu(Employee, Menu _menu) {
  SetMenu(_menu);
}*/

void MenuView::AllowSelection(bool allow) {
  if (allow) {
    setSelectionMode(QAbstractItemView::SingleSelection);
    this->model->SetColored(true);
    readOnly = false;
  } else {
    setSelectionMode(QAbstractItemView::NoSelection);
    this->model->SetColored(false);
    readOnly = true;
  }
}

void MenuView::SetSelection(double value, bool relative) {
  QModelIndexList list = selectedIndexes();
  if (list.size() == 0) {
    return;
  }

  QModelIndex selectedIndex = list[COUNT_COLUMN];
  QModelIndex selectedIndex2 = list[REMAIN_COLUMN];
  double currentCount;
  if (relative) {
    currentCount =
      model->data(selectedIndex, Qt::DisplayRole).toDouble();
    currentCount += value;
  } else {
    currentCount = value;
  }
  double maxCount = model->data(selectedIndex2, Qt::DisplayRole).toDouble();
  if (currentCount < 0)
    currentCount = 0;
  if (currentCount > maxCount)
    currentCount = maxCount;
  model->setData(selectedIndex, currentCount, Qt::DisplayRole);
  EmitTotalPrice();
}

void MenuView::IncSelectionByHalf() {
  SetSelection(0.5);
}

void MenuView::IncSelectionByOne() {
  SetSelection(1.0);
}

void MenuView::IncSelectionByFive() {
  SetSelection(5.0);
}

void MenuView::DecSelectionByHalf() {
  SetSelection(-0.5);
}

void MenuView::DecSelectionByOne() {
  SetSelection(-1.0);
}

void MenuView::DecSelectionByFive() {
  SetSelection(-5.0);
}

void MenuView::ZeroSelection() {
  SetSelection(0, false);
}

void MenuView::ZeroAll() {
  model->ZeroAll();
  emit EmitTotalPrice();
}

void MenuView::EmitTotalPrice() {
  emit TotalPrice(model->GetTotalPrice());
}

void MenuView::EmitOrder() {
  Menu m = model->GetOrder();
  if (m.size() > 0)
    emit Order(m);
}
