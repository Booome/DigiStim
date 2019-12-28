#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include "diginamespace.h"

class DataBase : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Digi::ConnectState_t conn_state
               READ getConnState
               WRITE setConnState
               RESET resetConnState
               NOTIFY connStateChanged
               FINAL)

private:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

public:
    static DataBase *getInstance() {
        if (!instance)
            instance = new DataBase;
        return instance;
    }

    Digi::ConnectState_t getConnState() {
        return conn_state;
    }

    void setConnState(Digi::ConnectState_t state) {
        conn_state = state;
    }

    void resetConnState() {
        conn_state = Digi::ConnectState_Disconnected;
    }

private:
    static DataBase *instance;

signals:
    void connStateChanged(Digi::ConnectState_t);

private:
    Digi::ConnectState_t conn_state;
};

#endif // DATABASE_H
