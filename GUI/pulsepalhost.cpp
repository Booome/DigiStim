#include "pulsepalhost.h"

PulsePalHost *PulsePalHost::instance = NULL;

PulsePalHost::PulsePalHost(QObject *parent)
    : QObject(parent)
{
}

PulsePalHost::~PulsePalHost()
{
}
