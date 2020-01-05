#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include "diginamespace.h"
#include <QDebug>

class DataBase : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Digi::ConnectState_t m_conn_state
               READ getConnState
               WRITE setConnState
               RESET resetConnState
               NOTIFY connStateChanged
               FINAL)

    Q_PROPERTY(QString m_dev_name
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
        static DataBase instance;
        return &instance;
    }

    Digi::ConnectState_t getConnState() const {
        return m_conn_state;
    }

    void setConnState(Digi::ConnectState_t state) {
        m_conn_state = state;
        emit connStateChanged(m_conn_state);
    }

    void resetConnState() {
        setConnState(Digi::ConnectState_Disconnected);
    }

    const QString &getDevName() const {
        return m_dev_name;
    }

    void setDevName(const QString &dev) {
        if (m_dev_name != dev) {
            m_dev_name = dev;
            emit devNameChanged(m_dev_name);
        }
    }

    void resetDevName() {
        setDevName("");
    }

signals:
    void connStateChanged(Digi::ConnectState_t);
    void devNameChanged(const QString &);

private:
    Digi::ConnectState_t m_conn_state;
    QString              m_dev_name;
};

#endif // DATABASE_H
