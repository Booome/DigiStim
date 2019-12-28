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

    Q_PROPERTY(QString dev_name
               READ getDevName
               WRITE setDevName
               RESET resetDevName
               NOTIFY devNameChanged
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

    Digi::ConnectState_t getConnState() const {
        return conn_state;
    }

    void setConnState(Digi::ConnectState_t state) {
        conn_state = state;
        emit connStateChanged(conn_state);
    }

    void resetConnState() {
        setConnState(Digi::ConnectState_Disconnected);
    }

    const QString &getDevName() const {
        return dev_name;
    }

    void setDevName(const QString &dev) {
        dev_name = dev;
        emit devNameChanged(dev_name);
    }

    void resetDevName() {
        setDevName("NULL");
    }

private:
    static DataBase *instance;

signals:
    void connStateChanged(Digi::ConnectState_t);
    void devNameChanged(const QString &);

private:
    Digi::ConnectState_t conn_state;
    QString              dev_name;
};

#endif // DATABASE_H
