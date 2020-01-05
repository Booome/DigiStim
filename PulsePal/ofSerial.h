#ifndef _OFSERIAL_H_
#define _OFSERIAL_H_

#include <string>
#include <vector>
#include <stdexcept>
#include <termios.h>
#include <stdexcept>

class ofSerialBaseError: public std::exception
{
private:
    std::string m_file;
    unsigned m_line;
    const std::string m_msg;

public:
    ofSerialBaseError(const std::string &file, unsigned line, const std::string &msg)
        : m_file(file), m_line(line), m_msg(msg) {}

    const char* what() const noexcept
    {
        return (m_file + " " + std::to_string(m_line) + ": " + m_msg).c_str();
    }
};

#define OFSERIAL_BLOCK_TIME_MAX         0xffffffff

class ofSerial
{
public:
    ofSerial();
    ofSerial(const std::string &port);
    ofSerial(const std::string &port, int baud);
    ~ofSerial();

    void open();
    void close() noexcept;
    bool opened() const noexcept { return m_fd >= 0; }

    void setPort(const std::string &port);
    void setBaud(int baud);

    ssize_t read(void *buf, int length);
    ssize_t write(const void *buf, int length);

    ssize_t readBlock(void *buf, int length, unsigned time_ms = OFSERIAL_BLOCK_TIME_MAX);
    ssize_t writeBlock(const void *buf, int length, unsigned time_ms = OFSERIAL_BLOCK_TIME_MAX);

public:
    static std::vector<std::string> scanPort();

private:
    std::string    m_port;
    int            m_baud;

    int            m_fd;
    struct termios oldoptions;
};

#endif // _OFSERIAL_H_
