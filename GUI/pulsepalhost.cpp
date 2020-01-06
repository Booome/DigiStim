#include "pulsepalhost.h"
#include "database.h"
#include <QDebug>
#include <unistd.h>

PulsePalHost::PulsePalHost(QObject *parent)
    : QObject(parent)
    , m_pulsepal(new PulsePal)
    , m_heatbeat_timer(new QTimer(this))
    , m_dev_name("")
{
    connect(m_heatbeat_timer, SIGNAL(timeout()), this, SLOT(on_heartbeat()));
    m_heatbeat_timer->start(1000);
}

PulsePalHost::~PulsePalHost()
{
    delete m_heatbeat_timer;
    delete m_pulsepal;
}

void PulsePalHost::deviceConnect()
{
    m_dev_name = DataBase::getInstance()->getDevName();
    if (m_dev_name == "")
        return;

    try {
        m_pulsepal->connect(m_dev_name.toStdString());
        DataBase::getInstance()->setConnState(Digi::ConnectState_Connected);
    } catch (std::exception &e) {
        qDebug() << e.what();
        deviceDisconnect();
    }
}

void PulsePalHost::deviceDisconnect()
{
    DataBase::getInstance()->setConnState(Digi::ConnectState_Disconnected);
    m_pulsepal->disconnect();
}

void PulsePalHost::doHeartbeat()
{
    try {
        m_pulsepal->getFirmwareVersion();
    }  catch (std::exception &e) {
        qDebug() << e.what();
        deviceDisconnect();
    }
}

void PulsePalHost::on_heartbeat()
{
    if (!m_pulsepal->connected()) {
        deviceConnect();
    } else {
        if (m_dev_name == DataBase::getInstance()->getDevName()) {
            doHeartbeat();
        } else {
            deviceDisconnect();
            deviceConnect();
        }
    }
}
