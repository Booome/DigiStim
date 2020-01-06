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

public slots:
    void on_devNameChange(const QString &);

private:
    PulsePal *m_pulsepal;
    QTimer   m_reconect_timer;
};

#endif // PULSEPALHOST_H
