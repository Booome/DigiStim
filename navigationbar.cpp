#include "navigationbar.h"
#include "style.h"
#include <QDebug>

NavigationBar::NavigationBar(QWidget *parent)
    : QWidget(parent)
    , home(new QPushButton(this))
    , back(new QPushButton(this))
{
}

NavigationBar::~NavigationBar()
{
    delete home;
}

void NavigationBar::setupUi(const QRect &rect)
{
    setGeometry(rect);

    QIcon icon_back(":/back.png");
    back->setGeometry(0, 0, geometry().height(), geometry().height());
    back->setIcon(icon_back);
    back->setIconSize(QSize(geometry().height(), geometry().height()));
    back->setStyleSheet(PUSH_BUTTON_STYLE);

    QIcon icon_home(":/home.png");
    home->setGeometry(geometry().height(), 0, geometry().height(), geometry().height());
    home->setIcon(icon_home);
    home->setIconSize(QSize(geometry().height(), geometry().height()));
    home->setStyleSheet(PUSH_BUTTON_STYLE);
}
