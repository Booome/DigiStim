#ifndef DIGINAMESPACE_H
#define DIGINAMESPACE_H

#include <QMetaType>

namespace Digi {

enum ConnectState_t {
    ConnectState_Disconnected,
    ConnectState_Handshaking,
    ConnectState_Connected
};

}

Q_DECLARE_METATYPE(Digi::ConnectState_t)

#endif // DIGINAMESPACE_H
