#ifndef CALIBRATEWINDOW_H
#define CALIBRATEWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include "calibratethread.h"

class CalibrateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalibrateWindow(QWidget *parent = nullptr);
    ~CalibrateWindow();

    void setupUi();

private:
    void resizeEvent(QResizeEvent *event);

signals:
    void isDone();

private:
    CalibrateThread *thread;
};

#endif // CALIBRATEWINDOW_H
