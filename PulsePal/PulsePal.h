#ifndef _PULSEPAL_H_
#define _PULSEPAL_H_

#include <string>

class PulsePal
{
public:
    PulsePal();
    ~PulsePal();

    void initiliaize(const std::string &port);

private:
    bool m_connectd;
};

#endif // _PULSEPAL_H_
