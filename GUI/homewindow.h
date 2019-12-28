#ifndef HOMEWINDOW_H
#define HOMEWINDOW_H

#include <QMainWindow>
#include "topbar.h"
#include "navigationbar.h"
#include "mwidget.h"

class HomeWindow : public QMainWindow
{
    Q_OBJECT

private:
    explicit HomeWindow(QWidget *parent = nullptr);
    ~HomeWindow();

public:
    static HomeWindow *getInstance() {
        if (!instance)
            instance = new HomeWindow();
        return instance;
    }

    void setupUi(const QRect &rect);

private:
    void resizeEvent(QResizeEvent *event);

    int geometries_x(int column);
    int geometries_y(int row);
    int geometries_w(int column);
    int geometries_h(int row);

private:
    static HomeWindow *instance;

private:
    TopBar        *topBar;
    NavigationBar *navigationBar;
    MWidget       *view;
};

#endif // HOMEWINDOW_H
