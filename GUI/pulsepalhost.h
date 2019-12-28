#ifndef PULSEPALHOST_H
#define PULSEPALHOST_H

#include <QObject>

class PulsePalHost : public QObject
{
    Q_OBJECT

public:
    explicit PulsePalHost(QObject *parent = nullptr);
    ~PulsePalHost();

public:
    static PulsePalHost *getInstance() {
        if (!instance)
            instance = new PulsePalHost;
        return instance;
    }

private:
    static PulsePalHost *instance;
};

#endif // PULSEPALHOST_H
