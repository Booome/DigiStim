#include "homewindow.h"

#include <QDebug>
#include <QGuiApplication>
#include <QLabel>

#define GAPS_PIXES                  5
#define BAR_HEIGHT_PIXES            60
#define TOP_BAR_STYLESHEET          "QWidget {background-color: white; border-radius: 8px;}"
#define NAVI_BAR_STYLESHEET         "QWidget {background-color: #b6b6b6; border-radius: 8px;}"

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

void HomeWindow::setupUi()
{
    topBar->setGeometry(GAPS_PIXES,
                        GAPS_PIXES,
                        geometry().width() - GAPS_PIXES * 2,
                        BAR_HEIGHT_PIXES);
    topBar->setStyleSheet(TOP_BAR_STYLESHEET);
    topBar->setupUi();

    navigationBar->setGeometry(GAPS_PIXES,
                               BAR_HEIGHT_PIXES + GAPS_PIXES * 2,
                               geometry().width() - GAPS_PIXES * 2,
                               BAR_HEIGHT_PIXES);
    navigationBar->setStyleSheet(NAVI_BAR_STYLESHEET);
    navigationBar->setupUi();
}
