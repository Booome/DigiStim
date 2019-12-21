#include "myapplication.h"
#include <QDebug>
#include <QScreen>
#include <QTimer>

MyApplication::MyApplication(int &argc, char **argv)
    : QApplication(argc, argv)
    , splash(new QSplashScreen)
    , home(NULL)
{
    splash->setPixmap(QPixmap(":/start.png"));
    splash->show();

    QTimer::singleShot(2500, this, SLOT(splashDone()));
}

MyApplication::~MyApplication()
{
    delete home;
    delete splash;
}

bool MyApplication::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
        qDebug() << watched->metaObject()->className()
                 << event->type();
    else if (event->type() == QEvent::MouseButtonRelease)
        qDebug() << watched->metaObject()->className()
                 << event->type();

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
