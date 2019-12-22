#include "calibratewindow.h"
#include <QDebug>

#include <QPushButton>

CalibrateWindow::CalibrateWindow(QWidget *parent)
    : QMainWindow(parent)
    , title(new QLabel(this))
    , prompt(new QLabel(this))
    , thread(new CalibrateThread(this))
{
    QObject::connect(thread, SIGNAL(isDone()), this, SIGNAL(isDone()));
}

CalibrateWindow::~CalibrateWindow()
{
    QObject::disconnect(thread, SIGNAL(isDone()), this, SIGNAL(isDone()));
    delete thread;
    delete prompt;
    delete title;
}

void CalibrateWindow::setupUi()
{
    title->setText(tr("Touchscreen calibration utility"));
    title->setStyleSheet("font: 16pt \"Adobe Courier\";");
    title->adjustSize();
    title->setGeometry((geometry().width() - title->geometry().width()) / 2,
                       geometry().height() * 6 / 20 - title->geometry().height() / 2,
                       title->geometry().width(),
                       title->geometry().height());

    prompt->setText(tr("Touch crosshair to calibrate"));
    prompt->setStyleSheet("font: 14pt \"Adobe Courier\";");
    prompt->adjustSize();
    prompt->setGeometry((geometry().width() - prompt->geometry().width()) / 2,
                        geometry().height() * 7 / 20 - prompt->geometry().height() / 2,
                        prompt->geometry().width(),
                        prompt->geometry().height());

    thread->start();
}

void CalibrateWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    setupUi();
}
