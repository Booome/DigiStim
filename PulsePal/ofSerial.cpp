#include "ofSerial.h"
#include "dirent.h"

using namespace std;

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
