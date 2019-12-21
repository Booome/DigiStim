#ifndef CALIBRATEWINDOW_H
#define CALIBRATEWINDOW_H

#include <QMainWindow>

class CalibrateWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit CalibrateWindow(QWidget *parent = nullptr);
    ~CalibrateWindow();

    void setupUi();

signals:

};

#endif // CALIBRATEWINDOW_H
