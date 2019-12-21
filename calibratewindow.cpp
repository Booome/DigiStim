#include "calibratewindow.h"

CalibrateWindow::CalibrateWindow(QWidget *parent)
    : QMainWindow(parent)
{
    installEventFilter(this);
}

CalibrateWindow::~CalibrateWindow()
{
}

void CalibrateWindow::setupUi()
{
}
