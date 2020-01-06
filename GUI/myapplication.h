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
    QSplashScreen   *m_splash;
    QThread         *m_pulsepale_thread;
    CalibrateWindow *m_calibrate_window;
    QTimer          *m_calibration_mode_timer;
};

#endif // MYAPPLICATION_H
