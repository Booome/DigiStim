#include "pulsepalhost.h"
#include "database.h"
#include <QDebug>

PulsePalHost::PulsePalHost(QObject *parent)
    : QObject(parent)
    , m_pulsepal(new PulsePal)
{
    connect(DataBase::getInstance(), SIGNAL(devNameChanged(const QString &)),
            this, SLOT(on_devNameChange(const QString &)));
}

PulsePalHost::~PulsePalHost()
{
}

void PulsePalHost::on_devNameChange(const QString &name)
{
    if (m_pulsepal->connected())
        m_pulsepal->disconnect();

    try {
        m_pulsepal->connect(name.toStdString());

        qDebug() << "firmware version: " << m_pulsepal->getFirmwareVersion();
    } catch (std::exception &e) {
        qDebug() << e.what();
    }
}
