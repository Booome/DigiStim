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
    const std::string m_msg;

public:
    PulsePalBaseError(const std::string &file, unsigned line, const std::string &msg)
        : m_file(file), m_line(line), m_msg(msg) {}

    const char* what() const noexcept
    {
        return (m_file + " " + std::to_string(m_line) + ": " + m_msg).c_str();
    }
};

class PulsePal
{
public:
    PulsePal();
    ~PulsePal();

    void connect(const std::string &port);
    void disconnect();

private:
    bool m_connectd;

private:
    ofSerial serial;
};

#endif // _PULSEPAL_H_
