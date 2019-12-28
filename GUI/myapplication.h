#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
#include <homewindow.h>
#include <calibratewindow.h>

class MyApplication : public QApplication
{
    Q_OBJECT

public:
    MyApplication(int &argc, char **argv);

    virtual ~MyApplication();

    bool eventFilter(QObject *watched, QEvent *event);

public slots:
    void splashDone();
    void calibrateModeToggle();

private:
    void calibrateCheck(QObject *watched, QEvent *event);
    void enterCalibrateMode();
    void exitCalibrateMode();

private slots:
    void calibrateDone();

private:
    QSplashScreen   *splash;
    HomeWindow      *home_window;
    CalibrateWindow *calibrate_window;
    QTimer          *calibration_mode_timer;
};

#endif // MYAPPLICATION_H
