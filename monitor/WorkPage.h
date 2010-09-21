#ifndef WORKPAGE_H
#define WORKPAGE_H

#include <QWidget>

namespace Ui {
    class WorkPage;
}

class WorkPage : public QWidget
{
    Q_OBJECT

public:
    explicit WorkPage(QWidget *parent = 0);
    ~WorkPage();

private:
    Ui::WorkPage *ui;
};

#endif // WORKPAGE_H
