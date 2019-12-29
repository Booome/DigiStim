#include "pulsepalhost.h"
#include "database.h"
#include <QDebug>

PulsePalHost::PulsePalHost(QObject *parent)
    : QObject(parent)
    , m_pulsepal(new PulsePal)
{
    connect(DataBase::getInstance(), SIGNAL(devNameChanged(const QString &)),
            this, SLOT());
}

PulsePalHost::~PulsePalHost()
{
}

void PulsePalHost::on_devNameChange(const QString &name)
{
}
