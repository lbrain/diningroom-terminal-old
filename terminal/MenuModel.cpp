#include "MenuModel.h"

const int COLUMNCOUNT = 4;
const int NAME_COLUMN = 0;
const int PRICE_COLUMN = 1;
const int COUNT_COLUMN = 2;
const int REMAIN_COLUMN = 3;

MenuModel::MenuModel(QObject *parent) :
    QAbstractTableModel(parent)
{
  SetColored(true);
}

MenuModel::MenuModel(bool _colored, QObject *parent) :
    QAbstractTableModel(parent)
{
  SetColored(_colored);
}

void MenuModel::SetMenu(Menu _menu) {
  menu = _menu;
  emit reset();
}

void MenuModel::SetMenu(Employee, Menu _menu) {
  menu = _menu;
  emit reset();
}

Qt::ItemFlags MenuModel::flags(const QModelIndex &index) const {
  if (!index.isValid())
    return 0;

  return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

bool MenuModel::setData(const QModelIndex &index, const QVariant &value, int role) {
  if (!index.isValid() || role != Qt::DisplayRole || index.column() != COUNT_COLUMN)
    return false;

  menu[index.row()].SetCount(value.toDouble());
  emit dataChanged(index, index);

  return true;
}

int MenuModel::columnCount(const QModelIndex&) const {
  return COLUMNCOUNT;
}

int MenuModel::rowCount(const QModelIndex&) const {
  return menu.size();
}

QVariant MenuModel::data(const QModelIndex &index, int role) const {
  if (!index.isValid())
    return QVariant();
  if (role == Qt::DisplayRole) {
    int row = index.row();
    int column = index.column();
    MenuEntry element = menu.at(row);
    return element.GetByColumnNumber(column+1);
  } else if (role == Qt::BackgroundRole && colored) {
    double x = data(this->index(index.row(), COUNT_COLUMN ), Qt::DisplayRole).toDouble();
    int fx = static_cast<int>((1/(x+2)*255*2));
    return QColor(fx, 255, fx);
  }
  return QVariant();
}

double MenuModel::GetTotalPrice() {
  return menu.GetTotalPrice();
}

Menu MenuModel::GetOrder() {
  return menu.GetOrder();
}

QVariant MenuModel::headerData(int section,
                               Qt::Orientation orientation,
                               int role) const {

  if (role == Qt::DisplayRole) {
    if (orientation == Qt::Vertical) {
      return menu[section].GetId();
    } else if (orientation == Qt::Horizontal) {
      switch (section) {
      case 0: {
          return QVariant("Name");
          break;
        }
      case 1: {
          return QVariant("Price");
          break;
        }
      case 2: {
          return QVariant("Count");
          break;
        }
      case 3: {
          return QVariant("Remaining");
          break;
        }
      }
    }
  } else if (role == Qt::BackgroundRole && colored && orientation == Qt::Vertical) {
    double x = data(this->index(section, COUNT_COLUMN ), Qt::DisplayRole).toDouble();
    int fx = static_cast<int>((1/(x+2)*200*2));
    return QColor(fx, 200, fx);
  }

  return QVariant();
}

void MenuModel::SetColored(bool x) {
  colored = x;
}

void MenuModel::ZeroAll() {
  menu.ZeroAll();
  emit dataChanged(index(0, COUNT_COLUMN), index(menu.size()-1, COUNT_COLUMN));
}
