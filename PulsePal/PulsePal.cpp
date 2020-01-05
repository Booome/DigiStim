#include "PulsePal.h"
#include <QDebug>

using namespace std;

#define PULSEPAL_THROW_STR(str) throw PulsePalBaseError(__FILE__, __LINE__, str)
#define PULSEPAL_THROW_STRERROR() throw PulsePalBaseError(__FILE__, __LINE__, strerror(errno))

PulsePal::PulsePal()
    : m_firmware_version(PULSEPAL_FIRMWARE_VERSION_INVALID)
{
}

PulsePal::~PulsePal()
{
}

void PulsePal::connect(const std::string &port)
{
    try {
        if (serial.opened())
            serial.close();

        serial.setPort(port);
        serial.setBaud(9600);

        serial.open();

        uint8_t handshake[2] = {213, 72};
        uint8_t response[5] = {};

        ssize_t ret = serial.writeBlock(handshake, sizeof(handshake), 100);
        if (ret != sizeof(handshake))
            PULSEPAL_THROW_STR("response time out.");

        ret = serial.readBlock(response, sizeof(response), 1000);
        if (ret != sizeof(response))
            PULSEPAL_THROW_STR("response time out.");

        if (response[0] != 75)
            PULSEPAL_THROW_STR("handshake[0] not correct.");

        m_firmware_version = makeUint32(&response[1]);
        if (m_firmware_version >= 40)
            PULSEPAL_THROW_STR("firmware version error.");
    } catch (ofSerialBaseError &e) {
        PULSEPAL_THROW_STR("serial error.");
    }
}

void PulsePal::disconnect()
{
    serial.close();
    m_firmware_version = PULSEPAL_FIRMWARE_VERSION_INVALID;
}

bool PulsePal::connected() const noexcept
{
    return m_firmware_version != PULSEPAL_FIRMWARE_VERSION_INVALID;
}

uint32_t PulsePal::getFirmwareVersion() const noexcept
{
    return m_firmware_version;
}

uint32_t PulsePal::makeUint32(void *start)
{
    uint8_t *byte = (uint8_t *)start;
    return byte[3] << 24 | byte[2] << 16 | byte[1] << 8 | byte[0];
}
