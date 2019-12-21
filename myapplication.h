#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
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
    void calibrationModeToggle();

private:
    void calibrationCheck(QObject *watched, QEvent *event);

private:
    QSplashScreen *splash;
    HomeWindow    *home;
    QTimer        *calibration_mode_timer;
};

#endif // MYAPPLICATION_H
