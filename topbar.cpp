#include "topbar.h"
#include "style.h"
#include <QDebug>

TopBar::TopBar(QWidget *parent)
    : MWidget(parent)
    , icon(new QLabel(this))
    , title(new QLabel(this))
    , reset(new QPushButton(this))
    , setting(new QPushButton(this))
{
}

TopBar::~TopBar()
{
    delete setting;
    delete reset;
    delete title;
    delete icon;
}

void TopBar::setupUi(const QRect &rect)
{
    setGeometry(rect);
    setStyleSheet(TOP_BAR_STYLESHEET);

    QPixmap pixmap_icon(":/icon.png");
    icon->setGeometry(0, 0, geometry().height(), geometry().height());
    icon->setPixmap(pixmap_icon);
    icon->setAlignment(Qt::AlignCenter);

    title->setGeometry(geometry().height(), 0,
                       geometry().width() - geometry().height() * 2,
                       geometry().height());
    title->setText(tr("Terminal"));
    title->setAlignment(Qt::AlignVCenter);
    title->setStyleSheet("font: 75 26pt \"Adobe Courier\";");

    QIcon icon_reset(":/reset.png");
    reset->setGeometry(geometry().width() - geometry().height() * 2.5, 0,
                       geometry().height(),
                       geometry().height());
    reset->setIcon(icon_reset);
    reset->setIconSize(QSize(geometry().height(), geometry().height()));
    reset->setStyleSheet(PUSH_BUTTON_STYLE);

    QIcon icon_setting(":/setting.png");
    setting->setGeometry(geometry().width() - geometry().height(), 0,
                         geometry().height(),
                         geometry().height());
    setting->setIcon(icon_setting);
    setting->setIconSize(QSize(geometry().height(), geometry().height()));
    setting->setStyleSheet(PUSH_BUTTON_STYLE);
}
