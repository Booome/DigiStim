#include "pulsepalhost.h"
#include <QDebug>

PulsePalHost::PulsePalHost(QObject *parent)
    : QThread(parent)
{
}

PulsePalHost::~PulsePalHost()
{
}

void PulsePalHost::run()
{
    while (!is_stop) {
    }
}
