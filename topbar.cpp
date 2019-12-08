#include "topbar.h"
#include <QDebug>

TopBar::TopBar(QWidget *parent)
    : QWidget(parent)
    , icon(new QLabel(this))
    , title(new QLabel(this))
    , setting(new QPushButton(this))
{
}

TopBar::~TopBar()
{
    delete icon;
}

void TopBar::setupUi()
{
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

    QIcon icon_setting(":/setting.png");
    setting->setGeometry(geometry().width() - geometry().height(), 0,
                         geometry().height(),
                         geometry().height());
    setting->setIcon(icon_setting);
    setting->setIconSize(QSize(geometry().height(), geometry().height()));
    setting->setStyleSheet(
                "QPushButton {background-color: #e3e3e3; border-radius: 8px;}"
                "QPushButton:pressed {background-color: #c6c6c6; border-radius: 8px;}"
                );
}
