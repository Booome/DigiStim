#include "calibratethread.h"
#include <QDebug>
#include <QElapsedTimer>

CalibrateThread::CalibrateThread(QObject *parent)
    : QThread(parent)
{
}

CalibrateThread::~CalibrateThread()
{
}

void CalibrateThread::run()
{
    qDebug() << __PRETTY_FUNCTION__;

    QElapsedTimer timer;
    timer.start();
    while (timer.elapsed() < 5000);

    emit isDone();
}
