#include "calibratewindow.h"
#include <QDebug>

#include <QPushButton>

#define CROSSHAIR_NUM       5

CalibrateWindow::CalibrateWindow(QWidget *parent)
    : QMainWindow(parent)
    , title(new QLabel(this))
    , prompt(new QLabel(this))
    , thread(new CalibrateThread(this))
    , crosshairs(new Crosshair[CROSSHAIR_NUM])
{
    QObject::connect(thread, SIGNAL(isDone()), this, SIGNAL(isDone()));

    for (int i = 0; i < CROSSHAIR_NUM; ++i)
        crosshairs[i].setParent(this);

    thread->start();
}

CalibrateWindow::~CalibrateWindow()
{
    QObject::disconnect(thread, SIGNAL(isDone()), this, SIGNAL(isDone()));

    delete thread;
    delete[] crosshairs;
    delete prompt;
    delete title;
}

void CalibrateWindow::setupUi()
{
    setupTitle();
    setupPrompt();
    setupCrosshairs();
}

void CalibrateWindow::setupTitle()
{
    title->setText(tr("Touchscreen calibration utility"));
    title->setStyleSheet("font: 16pt \"Adobe Courier\";");
    title->adjustSize();
    title->setGeometry((geometry().width() - title->geometry().width()) / 2,
                       geometry().height() * 6 / 20 - title->geometry().height() / 2,
                       title->geometry().width(),
                       title->geometry().height());
}

void CalibrateWindow::setupPrompt()
{
    prompt->setText(tr("Touch crosshair to calibrate"));
    prompt->setStyleSheet("font: 14pt \"Adobe Courier\";");
    prompt->adjustSize();
    prompt->setGeometry((geometry().width() - prompt->geometry().width()) / 2,
                        geometry().height() * 7 / 20 - prompt->geometry().height() / 2,
                        prompt->geometry().width(),
                        prompt->geometry().height());
}

void CalibrateWindow::setupCrosshairs()
{
    int XMGN = geometry().width() / 10;
    int YMGN = geometry().height() / 6;
    int SIDE = geometry().width() / 25;
    int HSIDE = SIDE / 2;

    QRect geometries[5] = {
        {XMGN - HSIDE, YMGN - HSIDE, SIDE, SIDE},
        {geometry().width() - XMGN - HSIDE, YMGN - HSIDE, SIDE, SIDE},
        {geometry().width() - XMGN - HSIDE, geometry().height() - YMGN - HSIDE, SIDE, SIDE},
        {XMGN - HSIDE, geometry().height() - YMGN - HSIDE, SIDE, SIDE},
        {geometry().width() / 2 - HSIDE, geometry().height() / 2 - HSIDE, SIDE, SIDE},
    };

    for (int i = 0; i < 5; ++i) {
        crosshairs[i].setGeometry(geometries[i]);
        crosshairs[i].setupUi();
    }
}

void CalibrateWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    setupUi();
}
