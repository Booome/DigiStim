#ifndef PULSEPALHOST_H
#define PULSEPALHOST_H

#include <QThread>
#include "PulsePal.h"
#include <QTimer>

class PulsePalHost : public QObject
{
    Q_OBJECT

private:
    explicit PulsePalHost(QObject *parent = nullptr);
    ~PulsePalHost();

public:
    static PulsePalHost *getInstance() {
        static PulsePalHost instance;
        return &instance;
    }

private:
    void deviceConnect();
    void deviceDisconnect();
    void doHeartbeat();

public slots:
    void on_heartbeat();

private:
    PulsePal *m_pulsepal;
    QTimer   *m_heatbeat_timer;

private:
    QString  m_dev_name;
};

#endif // PULSEPALHOST_H
