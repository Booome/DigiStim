#include "myapplication.h"
#include "pulsepalhost.h"
#include <QDebug>
#include <QScreen>

MyApplication::MyApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    , m_splash(new QSplashScreen)
    , m_calibrate_window(NULL)
    , m_calibration_mode_timer(new QTimer(this))
{
    m_splash->setPixmap(QPixmap(":/start.png"));
    m_splash->show();

    QTimer::singleShot(2500, this, SLOT(splashDone()));

    PulsePalHost::getInstance();

    m_calibration_mode_timer->setSingleShot(true);
    m_calibration_mode_timer->setInterval(5000);
    connect(m_calibration_mode_timer, SIGNAL(timeout()), this, SLOT(calibrateModeToggle()));

    installEventFilter(this);
}

MyApplication::~MyApplication()
{
    delete m_calibration_mode_timer;
    delete m_splash;
}

bool MyApplication::eventFilter(QObject *watched, QEvent *event)
{
    calibrateCheck(watched, event);
    return QApplication::eventFilter(watched, event);
}

void MyApplication::splashDone()
{
    m_splash->close();
    delete m_splash;
    m_splash = nullptr;

    HomeWindow *home_window = HomeWindow::getInstance();
    home_window->setupUi(QGuiApplication::primaryScreen()->geometry());
    home_window->show();
}

void MyApplication::calibrateModeToggle()
{
    qDebug() << __PRETTY_FUNCTION__;

    m_calibration_mode_timer->stop();

    HomeWindow *home_window = HomeWindow::getInstance();
    if (!home_window->isHidden()) {
        enterCalibrateMode();
        home_window->hide();
    } else {
        home_window->show();
        exitCalibrateMode();
    }
}

void MyApplication::calibrateCheck(QObject *watched, QEvent *event)
{
    Q_UNUSED(watched);

    if (event->type() == QEvent::MouseButtonPress) {
        m_calibration_mode_timer->stop();
        m_calibration_mode_timer->start();
    } else if (event->type() == QEvent::MouseButtonRelease) {
        m_calibration_mode_timer->stop();
    }
}

void MyApplication::enterCalibrateMode()
{
    m_calibrate_window = new CalibrateWindow;
    connect(m_calibrate_window, SIGNAL(isDone()), this, SLOT(calibrateDone()));
    m_calibrate_window->setupUi(QGuiApplication::primaryScreen()->geometry());
    m_calibrate_window->show();
}

void MyApplication::exitCalibrateMode()
{
    disconnect(m_calibrate_window, SIGNAL(isDone()), this, SLOT(calibrateDone()));
    delete m_calibrate_window;
    m_calibrate_window = nullptr;
}

void MyApplication::calibrateDone()
{
    HomeWindow *home_window = HomeWindow::getInstance();
    home_window->show();
    exitCalibrateMode();
}
