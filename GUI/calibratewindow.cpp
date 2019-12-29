#include "calibratewindow.h"
#include <QDebug>

#include <QPushButton>

#define CROSSHAIR_NUM       5

CalibrateWindow::CalibrateWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_title(new QLabel(this))
    , m_prompt(new QLabel(this))
    , m_thread(new CalibrateThread(this))
    , m_crosshairs(new Crosshair[CROSSHAIR_NUM])
{
    connect(m_thread, SIGNAL(isDone()), this, SIGNAL(isDone()));

    for (int i = 0; i < CROSSHAIR_NUM; ++i)
        m_crosshairs[i].setParent(this);

    m_thread->start();
}

CalibrateWindow::~CalibrateWindow()
{
    disconnect(m_thread, SIGNAL(isDone()), this, SIGNAL(isDone()));

    delete m_thread;
    delete[] m_crosshairs;
    delete m_prompt;
    delete m_title;
}

void CalibrateWindow::setupUi(const QRect &rect)
{
    setGeometry(rect);
    setupTitle();
    setupPrompt();
    setupCrosshairs();
}

void CalibrateWindow::setupTitle()
{
    m_title->setText(tr("Touchscreen calibration utility"));
    m_title->setStyleSheet("font: 16pt \"Adobe Courier\";");
    m_title->adjustSize();
    m_title->setGeometry((geometry().width() - m_title->geometry().width()) / 2,
                         geometry().height() * 6 / 20 - m_title->geometry().height() / 2,
                         m_title->geometry().width(),
                         m_title->geometry().height());
}

void CalibrateWindow::setupPrompt()
{
    m_prompt->setText(tr("Touch crosshair to calibrate"));
    m_prompt->setStyleSheet("font: 14pt \"Adobe Courier\";");
    m_prompt->adjustSize();
    m_prompt->setGeometry((geometry().width() - m_prompt->geometry().width()) / 2,
                          geometry().height() * 7 / 20 - m_prompt->geometry().height() / 2,
                          m_prompt->geometry().width(),
                          m_prompt->geometry().height());
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

    for (int i = 0; i < 5; ++i)
        m_crosshairs[i].setupUi(geometries[i]);
}

void CalibrateWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    setupUi(geometry());
}
