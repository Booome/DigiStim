#ifndef PULSEPALHOST_H
#define PULSEPALHOST_H

#include <QThread>

class PulsePalHost : public QThread
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

    void stop() { is_stop = true; }

protected:
    virtual void run();

private:
    volatile bool is_stop;
};

#endif // PULSEPALHOST_H
