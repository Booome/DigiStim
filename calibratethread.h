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

protected:
    void run();

signals:
    void isDone();
};

#endif // CALIBRATETHREAD_H
