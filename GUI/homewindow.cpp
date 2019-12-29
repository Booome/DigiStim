#include "homewindow.h"
#include "style.h"
#include <QDebug>
#include <QGuiApplication>
#include <QLabel>
#include "mainview.h"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , topBar(new TopBar(this))
    , navigationBar(new NavigationBar(this))
    , view(new MainView(this))
{
}

HomeWindow::~HomeWindow()
{
    delete view;
    delete navigationBar;
    delete topBar;
}

void HomeWindow::setupUi(const QRect &rect)
{
    setGeometry(rect);

    MWidget *widgets[] = {
        topBar,
        navigationBar,
        view,
    };

    const QRect geometries[] = {
        {geometries_x(0), geometries_y(0), geometries_w(0), geometries_h(0)},
        {geometries_x(0), geometries_y(1), geometries_w(0), geometries_h(1)},
        {geometries_x(0), geometries_y(2), geometries_w(0), geometries_h(2)}
    };

    for (size_t i = 0; i < sizeof(widgets) / sizeof(widgets[0]); ++i)
        widgets[i]->setupUi(geometries[i]);
}

void HomeWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    setupUi(geometry());
}

int HomeWindow::geometries_x(int column)
{
    Q_UNUSED(column)
    return GAPS_PIXES;
}

int HomeWindow::geometries_y(int row)
{
    switch (row) {
    case 0:
        return GAPS_PIXES;
    case 1:
        return geometries_y(0) + BAR_HEIGHT_PIXES + GAPS_PIXES;
    case 2:
        return geometries_y(1) + BAR_HEIGHT_PIXES + GAPS_PIXES;
    default:
        return -1;
    }
}

int HomeWindow::geometries_w(int column)
{
    Q_UNUSED(column)
    return geometry().width() - GAPS_PIXES * 2;
}

int HomeWindow::geometries_h(int row)
{
    switch (row) {
    case 0:
    case 1:
        return BAR_HEIGHT_PIXES;
    case 2:
        return geometry().height() - BAR_HEIGHT_PIXES * 2 - GAPS_PIXES * 4;
    default:
        return -1;
    }
}
