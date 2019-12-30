#include "topbar.h"
#include "style.h"
#include "database.h"
#include "ofSerial.h"
#include <QDebug>

TopBar::TopBar(QWidget *parent)
    : MWidget(parent)
    , m_icon(new QLabel(this))
    , m_title(new QLabel(this))
    , m_conn_state(new QLabel(this))
    , m_dev_name(new QPushButton(this))
    , m_reset(new QPushButton(this))
    , m_setting(new QPushButton(this))
{
    setAttribute(Qt::WA_StyledBackground);

    ofSerial serial;
    vector<ofSerialDeviceInfo> devices = serial.getDeviceList();
    if (devices.size())
        DataBase::getInstance()->setDevName(devices[0].getDeviceName().c_str());

    connect(DataBase::getInstance(), SIGNAL(connStateChanged(Digi::ConnectState_t)),
            this, SLOT(on_connStateChange(Digi::ConnectState_t)));
}

TopBar::~TopBar()
{
    delete m_setting;
    delete m_reset;
    delete m_title;
    delete m_icon;
}

void TopBar::setupUi(const QRect &rect)
{
    setGeometry(rect);
    setStyleSheet(TOP_BAR_STYLESHEET);

    setupIcon();
    setupTitle();
    setupConnState();
    setupDevName();
    setupReset();
    setupSetting();
}

void TopBar::setupIcon()
{
    QPixmap pixmap(":/icon.png");
    m_icon->setGeometry(0, 0, geometry().height(), geometry().height());
    m_icon->setPixmap(pixmap);
    m_icon->setAlignment(Qt::AlignCenter);
}

void TopBar::setupTitle()
{
    m_title->setGeometry(geometry().height(), 0,
                         geometry().width() / 2 - geometry().height() * 2,
                         geometry().height());
    m_title->setAlignment(Qt::AlignVCenter);
    m_title->setText(tr("Terminal"));
    m_title->setStyleSheet("font: 75 26pt \"Adobe Courier\";");
}

void TopBar::setupConnState()
{
    on_connStateChange(DataBase::getInstance()->getConnState());
}

void TopBar::setupDevName()
{
    if (DataBase::getInstance()->getDevName() == "")
        on_devNameChange("NULL");
    else
        on_devNameChange(DataBase::getInstance()->getDevName());
}

void TopBar::setupReset()
{
    QIcon icon(":/reset.png");
    m_reset->setGeometry(geometry().width() - geometry().height() * 2.25, 0,
                         geometry().height(),
                         geometry().height());
    m_reset->setIcon(icon);
    m_reset->setIconSize(QSize(geometry().height(), geometry().height()));
    m_reset->setStyleSheet(PUSH_BUTTON_STYLE);
}

void TopBar::setupSetting()
{
    QIcon icon(":/setting.png");
    m_setting->setGeometry(geometry().width() - geometry().height(), 0,
                           geometry().height(),
                           geometry().height());
    m_setting->setIcon(icon);
    m_setting->setIconSize(QSize(geometry().height(), geometry().height()));
    m_setting->setStyleSheet(PUSH_BUTTON_STYLE);
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

    QPixmap pixmap(filename);
    m_conn_state->setGeometry(geometry().width() / 2 - geometry().height(), 0,
                              geometry().height(), geometry().height());
    m_conn_state->setPixmap(pixmap);
    m_conn_state->setAlignment(Qt::AlignCenter);
}

void TopBar::on_devNameChange(const QString &dev)
{
    m_dev_name->setGeometry(geometry().width() / 2, 0,
                            geometry().width() / 2 - geometry().height() * 2.5,
                            geometry().height());
    m_dev_name->setText(dev);
    m_dev_name->setFont(QFont("Adobe Courier", 20));
    m_dev_name->setStyleSheet("QPushButton {background-color: #F0F0F0; border-radius: 8px;}"
                              "QPushButton:pressed {background-color: #C6C6C6; border-radius: 8px;}");
}
