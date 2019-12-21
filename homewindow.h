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

private:
    void resizeEvent(QResizeEvent *event);

private:
    TopBar        *topBar;
    NavigationBar *navigationBar;
};

#endif // HOMEWINDOW_H
