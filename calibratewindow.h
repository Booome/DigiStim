#ifndef CALIBRATEWINDOW_H
#define CALIBRATEWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QLabel>
#include <QVector>
#include "calibratethread.h"
#include "crosshair.h"

class CalibrateWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit CalibrateWindow(QWidget *parent = nullptr);
    ~CalibrateWindow();

    void setupUi(const QRect &rect);

private:
    void resizeEvent(QResizeEvent *event);
    void setupTitle();
    void setupPrompt();
    void setupCrosshairs();

signals:
    void isDone();

private:
    QLabel          *title;
    QLabel          *prompt;
    CalibrateThread *thread;
    Crosshair       *crosshairs;
};

#endif // CALIBRATEWINDOW_H
