#include "ofSerial.h"
#include "dirent.h"
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

using namespace std;

#define OFSERIAL_THROW_STR(str) throw ofSerialBaseError(__FILE__, __LINE__, str)
#define OFSERIAL_THROW_STRERROR() throw ofSerialBaseError(__FILE__, __LINE__, strerror(errno))

ofSerial::ofSerial()
    : ofSerial("", 115200)
{
}

ofSerial::ofSerial(const std::string &port)
    : ofSerial(port, 115200)
{
}

ofSerial::ofSerial(const std::string &port, int baud)
    : m_port(port)
    , m_baud(baud)
    , m_fd(-1)
{
}

ofSerial::~ofSerial()
{
}

void ofSerial::open()
{
    struct {
        int     baud_rate;
        speed_t termios_speed;
    } speed_map[] = {
        {0, B0},
        {50, B50},
        {75, B75},
        {110, B110},
        {134, B134},
        {150, B150},
        {200, B200},
        {300, B300},
        {600, B600},
        {1200, B1200},
        {1800, B1800},
        {2400, B2400},
        {4800, B4800},
        {9600, B9600},
        {19200, B19200},
        {38400, B38400},
        {57600, B57600},
        {115200, B115200},
        {230400, B230400},
    };
    speed_t speed = (speed_t)-1;

    if (m_fd >= 0)
        ::close(m_fd);

    m_fd = ::open(m_port.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (m_fd < 0)
        OFSERIAL_THROW_STRERROR();

    int ret;
    struct termios options;
    ret = tcgetattr(m_fd, &oldoptions);
    if (ret == -1) {
        ::close(m_fd);
        m_fd = -1;
        OFSERIAL_THROW_STRERROR();
    }
    options = oldoptions;

    for (size_t i = 0; i < sizeof (speed_map) / sizeof(speed_map[0]); ++i) {
        if (m_baud == speed_map[i].baud_rate)
            speed = speed_map[i].termios_speed;
    }
    if (speed == (speed_t)-1) {
        ::close(m_fd);
        m_fd = -1;
        tcsetattr(m_fd, TCSANOW, &oldoptions);
        OFSERIAL_THROW_STRERROR();
    }

    ret = cfsetispeed(&options, speed);
    if (ret == -1) {
        ::close(m_fd);
        m_fd = -1;
        tcsetattr(m_fd, TCSANOW, &oldoptions);
        OFSERIAL_THROW_STRERROR();
    }
    ret = cfsetospeed(&options, speed);
    if (ret == -1) {
        ::close(m_fd);
        m_fd = -1;
        tcsetattr(m_fd, TCSANOW, &oldoptions);
        OFSERIAL_THROW_STRERROR();
    }

    options.c_cflag |= (CLOCAL | CREAD);
    options.c_cflag &= ~PARENB;
    options.c_cflag &= ~CSTOPB;
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;

    cfmakeraw(&options);

    ret = tcsetattr(m_fd, TCSANOW, &options);
    if (ret == -1) {
        ::close(m_fd);
        m_fd = -1;
        tcsetattr(m_fd, TCSANOW, &oldoptions);
        OFSERIAL_THROW_STRERROR();
    }
}

void ofSerial::close() noexcept
{
    if (m_fd <= 0)
        return;

    tcsetattr(m_fd, TCSANOW, &oldoptions);
    ::close(m_fd);
    m_fd = -1;
}

void ofSerial::setPort(const std::string &port)
{
    if (opened())
        OFSERIAL_THROW_STR("close port first.");

    m_port = port;
}

void ofSerial::setBaud(int baud)
{
    if (opened())
        OFSERIAL_THROW_STR("close port first.");

    m_baud = baud;
}

ssize_t ofSerial::read(void *buf, int length)
{
    if (!opened())
        OFSERIAL_THROW_STR("open port first.");

    ssize_t ret = ::read(m_fd, buf, length);
    if (ret != -1)
        return ret;

    if (errno == EAGAIN)
        return 0;

    OFSERIAL_THROW_STRERROR();
}

ssize_t ofSerial::write(const void *buf, int length)
{
    if (!opened())
        OFSERIAL_THROW_STR("open port first.");

    ssize_t ret = ::write(m_fd, buf, length);
    if (ret != -1)
        return ret;

    if (errno == EAGAIN)
        return 0;

    OFSERIAL_THROW_STRERROR();
}

ssize_t ofSerial::readBlock(void *buf, int length, unsigned time_ms)
{
    ssize_t num = 0;

    while (num < length) {
        num += read((uint8_t *)buf + num, length - num);
        if (!time_ms)
            break;
        else if (time_ms != OFSERIAL_BLOCK_TIME_MAX)
            --time_ms;
        usleep(1000);
    }

    return num;
}

ssize_t ofSerial::writeBlock(const void *buf, int length, unsigned time_ms)
{
    ssize_t num = 0;

    while (num < length) {
        num += write((uint8_t *)buf + num, length - num);
        if (!time_ms)
            break;
        else if (time_ms != OFSERIAL_BLOCK_TIME_MAX)
            --time_ms;
        usleep(1000);
    }

    return num;
}

vector<string> ofSerial::scanPort()
{
    vector<string> devices;

    vector<string> prefixMatch;
    prefixMatch.push_back("ttyACM");

    DIR *dir;
    struct dirent* entry;
    dir = opendir("/dev");

    string deviceName = "";

    if (dir == NULL)
        return devices;

    while ((entry = readdir(dir)) != NULL) {
        deviceName = (char*)entry->d_name;

        for (int k = 0; k < (int)prefixMatch.size(); k++) {
            if (deviceName.size() > prefixMatch[k].size()) {
                if (deviceName.substr(0, prefixMatch[k].size()) == prefixMatch[k].c_str()) {
                    devices.push_back("/dev/" + deviceName);
                    break;
                }
            }
        }
    }

    closedir(dir);
    return devices;
}
