#include "calibratethread.h"
#include <QDebug>
#include <QElapsedTimer>
#include <QDateTime>

CalibrateThread::CalibrateThread(QObject *parent)
    : QThread(parent)
    , stopped(false)
{
}

void CalibrateThread::stop()
{
    qDebug() << __FUNCTION__ << __LINE__;
    stopped = true;
}

CalibrateThread::~CalibrateThread()
{
    stopped = true;
    wait();
}

void CalibrateThread::run()
{
    while (!stopped) {
    }

    emit isDone();
    quit();
}
