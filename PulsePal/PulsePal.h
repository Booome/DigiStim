#ifndef _PULSEPAL_H_
#define _PULSEPAL_H_

#include <string>
#include "ofSerial.h"
#include <stdexcept>

class PulsePalBaseError: public std::exception
{
private:
    std::string m_file;
    unsigned m_line;
    std::string m_msg;
    std::string m_full_msg;

public:
    PulsePalBaseError(const std::string &file, unsigned line, const std::string &msg)
        : m_file(file), m_line(line), m_msg(msg)
    {
        m_full_msg = m_file + " " + std::to_string(m_line) + ": " + m_msg;
    }

    const char* what() const noexcept
    {
        return m_full_msg.c_str();
    }
};

#define PULSEPAL_FIRMWARE_VERSION_INVALID       0xffffffff

class PulsePal
{
public:
    PulsePal();
    ~PulsePal();

    void connect(const std::string &port);
    void disconnect();
    bool connected() const noexcept;

    uint32_t getFirmwareVersion() const noexcept;

private:
    uint32_t makeUint32(void *start);

private:
    uint32_t m_firmware_version;

private:
    ofSerial serial;
};

#endif // _PULSEPAL_H_
