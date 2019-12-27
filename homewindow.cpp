#include "homewindow.h"
#include "style.h"
#include <QDebug>
#include <QGuiApplication>
#include <QLabel>

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , topBar(new TopBar(this))
    , navigationBar(new NavigationBar(this))
{
}

HomeWindow::~HomeWindow()
{
    delete navigationBar;
    delete topBar;
}

void HomeWindow::setupUi(const QRect &rect)
{
    setGeometry(rect);

    MWidget *widgets[] = {
        topBar,
        navigationBar
    };

    const QRect geometries[] = {
        {GAPS_PIXES, GAPS_PIXES, geometry().width() - GAPS_PIXES * 2, BAR_HEIGHT_PIXES},
        {GAPS_PIXES, BAR_HEIGHT_PIXES + GAPS_PIXES * 2, geometry().width() - GAPS_PIXES * 2, BAR_HEIGHT_PIXES}
    };

    for (size_t i = 0; i < sizeof(widgets) / sizeof(widgets[0]); ++i)
        widgets[i]->setupUi(geometries[i]);
}

void HomeWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event)
    setupUi(geometry());
}
