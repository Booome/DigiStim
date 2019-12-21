#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include <QSplashScreen>
#include <homewindow.h>

class MyApplication : public QApplication
{
    Q_OBJECT

public:
    MyApplication(int &argc, char **argv);

    virtual ~MyApplication();

    bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void splashDone();

private:
    QSplashScreen *splash;
    HomeWindow    *home;
};

#endif // MYAPPLICATION_H
