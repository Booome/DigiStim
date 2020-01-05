#include "PulsePal.h"

using namespace std;

PulsePal::PulsePal()
    : m_connectd(false)
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
        serial.setBaud(115200);

        serial.open();

        uint8_t response[5] = {};
        uint8_t handshake[2] = {213, 72};
        serial.writeBlock(handshake, sizeof(handshake), 100);
        ssize_t ret = serial.readBlock(response, sizeof(response), 100);

    }  catch (ofSerialBaseError &e) {
        serial.close();
    }
}
