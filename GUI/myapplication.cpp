#include "myapplication.h"
#include <QDebug>
#include <QScreen>

MyApplication::MyApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    , splash(new QSplashScreen)
    , calibrate_window(NULL)
    , calibration_mode_timer(new QTimer(this))
{
    splash->setPixmap(QPixmap(":/start.png"));
    splash->show();

    QTimer::singleShot(2500, this, SLOT(splashDone()));

    calibration_mode_timer->setSingleShot(true);
    calibration_mode_timer->setInterval(5000);
    connect(calibration_mode_timer, SIGNAL(timeout()), this, SLOT(calibrateModeToggle()));

    installEventFilter(this);
}

MyApplication::~MyApplication()
{
    delete calibration_mode_timer;
    delete splash;
}

bool MyApplication::eventFilter(QObject *watched, QEvent *event)
{
    calibrateCheck(watched, event);
    return QApplication::eventFilter(watched, event);
}

void MyApplication::splashDone()
{
    splash->close();
    delete splash;
    splash = nullptr;

    HomeWindow *home_window = HomeWindow::getInstance();
    home_window->setupUi(QGuiApplication::primaryScreen()->geometry());
    home_window->show();
}

void MyApplication::calibrateModeToggle()
{
    qDebug() << __PRETTY_FUNCTION__;

    calibration_mode_timer->stop();

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
        calibration_mode_timer->stop();
        calibration_mode_timer->start();
    } else if (event->type() == QEvent::MouseButtonRelease) {
        calibration_mode_timer->stop();
    }
}

void MyApplication::enterCalibrateMode()
{
    calibrate_window = new CalibrateWindow;
    QObject::connect(calibrate_window, SIGNAL(isDone()), this, SLOT(calibrateDone()));
    calibrate_window->setupUi(QGuiApplication::primaryScreen()->geometry());
    calibrate_window->show();
}

void MyApplication::exitCalibrateMode()
{
    QObject::disconnect(calibrate_window, SIGNAL(isDone()), this, SLOT(calibrateDone()));
    delete calibrate_window;
    calibrate_window = nullptr;
}

void MyApplication::calibrateDone()
{
    HomeWindow *home_window = HomeWindow::getInstance();
    home_window->show();
    exitCalibrateMode();
}
