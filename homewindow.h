#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include "topbar.h"
#include "navigationbar.h"

class HomeWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

    void setupUi();
    bool event(QEvent *event);

private:
    void resizeEvent(QResizeEvent *event);

private:
    TopBar *topBar;
    NavigationBar *navigationBar;

signals:

public slots:

};

#endif // HOMEWINDOW_H
