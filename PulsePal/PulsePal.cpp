#include "PulsePal.h"
#include <QDebug>

using namespace std;

#define PULSEPAL_THROW_STR(str) throw PulsePalBaseError(__FILE__, __LINE__, str)
#define PULSEPAL_THROW_STRERROR() throw PulsePalBaseError(__FILE__, __LINE__, strerror(errno))

PulsePal::PulsePal()
{
}

PulsePal::~PulsePal()
{
}

void PulsePal::connect(const std::string &port)
{
    if (m_serial.opened())
        m_serial.close();

    m_serial.setPort(port);
    m_serial.setBaud(9600);
    m_serial.open();

    getFirmwareVersion();

    m_connected = true;
}

void PulsePal::disconnect()
{
    m_connected = false;
    m_serial.close();
}

bool PulsePal::connected() const noexcept
{
    return m_connected;
}

uint32_t PulsePal::getFirmwareVersion()
{
    uint32_t firmware_version;
    uint8_t handshake[2] = {213, 72};
    uint8_t response[5] = {};

    ssize_t ret = m_serial.writeBlock(handshake, sizeof(handshake), 100);
    if (ret != sizeof(handshake))
        PULSEPAL_THROW_STR("response time out.");

    ret = m_serial.readBlock(response, sizeof(response), 1000);
    if (ret != sizeof(response))
        PULSEPAL_THROW_STR("response time out.");

    if (response[0] != 75)
        PULSEPAL_THROW_STR("handshake[0] not correct.");

    firmware_version = makeUint32(&response[1]);
    if (firmware_version >= 40)
        PULSEPAL_THROW_STR("firmware version error.");

    return firmware_version;
}

uint32_t PulsePal::makeUint32(void *start)
{
    uint8_t *byte = (uint8_t *)start;
    return byte[3] << 24 | byte[2] << 16 | byte[1] << 8 | byte[0];
}
