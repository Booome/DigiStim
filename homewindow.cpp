#include "homewindow.h"

#include <QDebug>
#include <QGuiApplication>
#include <QScreen>

#define GAPS_PIXES              5
#define BAR_HEIGHT_PIXES        60
#define BAR_STYLESHEET          "QWidget {background-color: #b6b6b6; border-radius: 8px;}"

HomeWindow::HomeWindow(QWidget *parent)
    : QMainWindow(parent)
    , topBar(nullptr)
    , navigationBar(nullptr)
{
    setGeometry(QGuiApplication::primaryScreen()->geometry());

    // topBar
    topBar = new TopBar(this);
    topBar->setGeometry(GAPS_PIXES,
                        GAPS_PIXES,
                        geometry().width() - GAPS_PIXES * 2,
                        BAR_HEIGHT_PIXES);
    topBar->setStyleSheet(BAR_STYLESHEET);

    // navigationBar
    navigationBar = new NavigationBar(this);
    navigationBar->setGeometry(GAPS_PIXES,
                               BAR_HEIGHT_PIXES + GAPS_PIXES * 2,
                               geometry().width() - GAPS_PIXES * 2,
                               BAR_HEIGHT_PIXES);
    navigationBar->setStyleSheet(BAR_STYLESHEET);
}

HomeWindow::~HomeWindow()
{
    delete navigationBar;
    delete topBar;
}
