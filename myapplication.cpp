#include "myapplication.h"
#include <QDebug>
#include <QScreen>

MyApplication::MyApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    , splash(new QSplashScreen)
    , home(NULL)
    , calibration_mode_timer(new QTimer(this))
{
    splash->setPixmap(QPixmap(":/start.png"));
    splash->show();

    QTimer::singleShot(2500, this, SLOT(splashDone()));

    calibration_mode_timer->setSingleShot(true);
    connect(calibration_mode_timer, SIGNAL(timeout()), this, SLOT(calibrationModeToggle()));
}

MyApplication::~MyApplication()
{
    delete calibration_mode_timer;
    delete home;
    delete splash;
}

bool MyApplication::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress) {
        calibration_mode_timer->stop();
        calibration_mode_timer->setInterval(5000);
        calibration_mode_timer->start();
    } else if (event->type() == QEvent::MouseButtonRelease) {
        calibration_mode_timer->stop();
    }

    return QApplication::eventFilter(watched, event);
}

void MyApplication::splashDone()
{
    splash->close();
    delete splash;
    splash = nullptr;

    home = new HomeWindow;
    home->setGeometry(QGuiApplication::primaryScreen()->geometry());
    home->setupUi();
    home->show();
}

void MyApplication::calibrationModeToggle()
{
    if (!home->isHidden()) {
        qDebug() << "Enter Calibration Mode";
    } else {
        qDebug() << "Exit Calibration Mode";
    }
}
