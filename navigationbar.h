#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include "mwidget.h"
#include <QPushButton>

class NavigationBar: public MWidget
{
public:
    explicit NavigationBar(QWidget *parent = nullptr);
    virtual ~NavigationBar();

    virtual void setupUi(const QRect &rect);

private:
    QPushButton *home;
    QPushButton *back;
};

#endif // NAVIGATIONBAR_H
