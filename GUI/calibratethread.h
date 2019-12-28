#ifndef CALIBRATETHREAD_H
#define CALIBRATETHREAD_H

#include <QThread>
#include <QObject>

class CalibrateThread : public QThread
{
    Q_OBJECT

public:
    explicit CalibrateThread(QObject *parent = 0);
    ~CalibrateThread();

    void stop();

protected:
    void run();

signals:
    void isDone();

private:
    volatile bool stopped;
};

#endif // CALIBRATETHREAD_H
