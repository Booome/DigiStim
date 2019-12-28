#include "topbar.h"
#include "style.h"
#include "database.h"
#include <QDebug>

TopBar::TopBar(QWidget *parent)
    : MWidget(parent)
    , icon(new QLabel(this))
    , title(new QLabel(this))
    , conn_state(new QLabel(this))
    , dev_name(new QPushButton(this))
    , reset(new QPushButton(this))
    , setting(new QPushButton(this))
{
    setAttribute(Qt::WA_StyledBackground);

    QObject::connect(DataBase::getInstance(), SIGNAL(connStateChanged), this, SLOT(on_connStateChange(Digi::ConnectState_t)));
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

    setupIcon();
    setupTitle();
    setupConnState();
    setupReset();
    setupSetting();
}

void TopBar::setupIcon()
{
    QPixmap pixmap(":/icon.png");
    icon->setGeometry(0, 0, geometry().height(), geometry().height());
    icon->setPixmap(pixmap);
    icon->setAlignment(Qt::AlignCenter);
}

void TopBar::setupTitle()
{
    title->setGeometry(geometry().height(), 0,
                       geometry().width() / 2 - geometry().height() * 2,
                       geometry().height());
    title->setAlignment(Qt::AlignVCenter);
    title->setText(tr("Terminal"));
    title->setStyleSheet("font: 75 26pt \"Adobe Courier\";");
}

void TopBar::setupConnState()
{
    Digi::ConnectState_t _conn_state = DataBase::getInstance()->getConnState();
    on_connStateChange(_conn_state);
}

void TopBar::setupReset()
{
    QIcon icon(":/reset.png");
    reset->setGeometry(geometry().width() - geometry().height() * 2.5, 0,
                       geometry().height(),
                       geometry().height());
    reset->setIcon(icon);
    reset->setIconSize(QSize(geometry().height(), geometry().height()));
    reset->setStyleSheet(PUSH_BUTTON_STYLE);
}

void TopBar::setupSetting()
{
    QIcon icon(":/setting.png");
    setting->setGeometry(geometry().width() - geometry().height(), 0,
                         geometry().height(),
                         geometry().height());
    setting->setIcon(icon);
    setting->setIconSize(QSize(geometry().height(), geometry().height()));
    setting->setStyleSheet(PUSH_BUTTON_STYLE);
}

void TopBar::on_connStateChange(Digi::ConnectState_t _conn_state)
{
    QString filename;
    if (_conn_state == Digi::ConnectState_Disconnected)
        filename = ":/disconnected.png";
    else if (_conn_state == Digi::ConnectState_Handshaking)
        filename = ":/handshaking.png";
    else if (_conn_state == Digi::ConnectState_Connected)
        filename = ":/connected.png";

    qDebug() << filename;

    QPixmap pixmap(filename);
    conn_state->setGeometry(geometry().width() / 2 - geometry().height(), 0,
                            geometry().height(), geometry().height());
    conn_state->setPixmap(pixmap);
    conn_state->setAlignment(Qt::AlignCenter);
}
