#include <QApplication>
#include <QDebug>
#include <QSplashScreen>
#include <QTimer>
#include <QScreen>

#include "homewindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap(":/start.png"));
    splash->show();

    HomeWindow w;
    w.setGeometry(QGuiApplication::primaryScreen()->geometry());
    w.setupUi();

    QTimer::singleShot(2500, splash, SLOT(close()));
    QTimer::singleShot(2500, &w, SLOT(show()));

    return app.exec();
}
