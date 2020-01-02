#ifndef _OFSERIAL_H_
#define _OFSERIAL_H_

#include <string>
#include <vector>

class ofSerial
{
public:
    static std::vector<std::string> scanPort();
};

#endif // _OFSERIAL_H_
