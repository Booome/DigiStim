#include "calibratethread.h"
#include <QDebug>

CalibrateThread::CalibrateThread(QObject *parent)
    : QThread(parent)
    , m_stopped(false)
{
}

void CalibrateThread::stop()
{
    qDebug() << __FUNCTION__ << __LINE__;
    m_stopped = true;
}

CalibrateThread::~CalibrateThread()
{
    m_stopped = true;
    wait();
}

void CalibrateThread::run()
{
    while (!m_stopped) {
    }

    emit isDone();
    quit();
}
