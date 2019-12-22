#include "calibratewindow.h"
#include <QDebug>

#include <QPushButton>

CalibrateWindow::CalibrateWindow(QWidget *parent)
    : QMainWindow(parent)
    , thread(new CalibrateThread(this))
{
    QObject::connect(thread, SIGNAL(isDone()), this, SIGNAL(isDone()));
}

CalibrateWindow::~CalibrateWindow()
{
    QObject::disconnect(thread, SIGNAL(isDone()), this, SIGNAL(isDone()));
    delete thread;
}

void CalibrateWindow::setupUi()
{
    thread->start();
}

void CalibrateWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    setupUi();
}
