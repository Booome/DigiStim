#include "navigationbar.h"
#include "style.h"
#include <QDebug>

NavigationBar::NavigationBar(QWidget *parent)
    : MWidget(parent)
    , m_home(new QPushButton(this))
    , m_back(new QPushButton(this))
{
    setAttribute(Qt::WA_StyledBackground);
}

NavigationBar::~NavigationBar()
{
    delete m_home;
}

void NavigationBar::setupUi(const QRect &rect)
{
    setGeometry(rect);
    setStyleSheet(NAVI_BAR_STYLESHEET);

    QIcon icon_back(":/back.png");
    m_back->setGeometry(0, 0, geometry().height(), geometry().height());
    m_back->setIcon(icon_back);
    m_back->setIconSize(QSize(geometry().height(), geometry().height()));
    m_back->setStyleSheet(PUSH_BUTTON_STYLE);

    QIcon icon_home(":/home.png");
    m_home->setGeometry(geometry().height(), 0, geometry().height(), geometry().height());
    m_home->setIcon(icon_home);
    m_home->setIconSize(QSize(geometry().height(), geometry().height()));
    m_home->setStyleSheet(PUSH_BUTTON_STYLE);
}
