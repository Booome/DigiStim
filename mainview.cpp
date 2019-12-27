#include "mainview.h"

MainView::MainView(QWidget *parent)
    : QWidget(parent)
    , outter_gaps(10)
    , inner_gaps(5)
    , radius(20)
{
    for (int i = 0; i < TRIGGER_BUTTON_NUM; ++i)
        triggers[i] = new QPushButton;

    for (int i = 0; i < CHANNEL_BUTTON_NUM; ++i)
        channels[i] = new QPushButton;
}

MainView::~MainView()
{
    for (int i = 0; i < TRIGGER_BUTTON_NUM; ++i)
        delete triggers[i];

    for (int i = 0; i < CHANNEL_BUTTON_NUM; ++i)
        delete channels[i];
}

void MainView::setupUi(const QRect &rect)
{
    setGeometry(rect);

    setupTriggers();
    setupChannels();
}

void MainView::setupTriggers()
{
    const QRect geometries[] = {
        {geometries_x(0), geometries_y(0), triggerButtonWith(), triggerButtonHeight()},
        {geometries_x(0), geometries_y(1), triggerButtonWith(), triggerButtonHeight()}
    };

    const QString styles[] = {
        "QPushButton:pressed {background-color: #c6c6c6; border-top-left-radius: " + QString::number(radius) + "px; border-top-right-radius:"  + QString::number(radius) + "px;}",
        "QPushButton:pressed {background-color: #c6c6c6; border-bottom-left-radius:" + QString::number(radius) + "px; border-bottom-right-radius:" + QString::number(radius) + "px;}"
    };
}

void MainView::setupChannels()
{
    const QRect geometries[] = {
        {geometries_x(1), geometries_y(0), channelButtonWith(), channelButtonHeight()},
        {geometries_x(0), geometries_y(1), channelButtonWith(), channelButtonHeight()},
        {geometries_x(0), geometries_y(1), channelButtonWith(), channelButtonHeight()},
        {geometries_x(0), geometries_y(1), channelButtonWith(), channelButtonHeight()}
    };

    const QString styles[] = {
        "QPushButton:pressed {background-color: #c6c6c6; border-top-left-radius: " + QString::number(radius) + "px; border-top-right-radius:"  + QString::number(radius) + "px;}",
        "QPushButton:pressed {background-color: #c6c6c6; border-bottom-left-radius:" + QString::number(radius) + "px; border-bottom-right-radius:" + QString::number(radius) + "px;}"
    };
}

int MainView::triggerButtonWith()
{
    return (geometry().width() - 3 * outter_gaps - inner_gaps) / 5;
}

int MainView::triggerButtonHeight()
{
    return (geometry().height() - 2 * outter_gaps - inner_gaps) / 2;
}

int MainView::channelButtonWith()
{
    return triggerButtonWith() * 2;
}

int MainView::channelButtonHeight()
{
    return triggerButtonHeight();
}

int MainView::geometries_x(int cloume)
{
    switch (cloume) {
    case 0:
        return outter_gaps;
    case 1:
        return geometries_x(0) + triggerButtonWith() + outter_gaps;
    case 2:
        return geometries_x(1) + channelButtonWith() + inner_gaps;
    default:
        return -1;
    }
}

int MainView::geometries_y(int row)
{
    switch (row) {
    case 0:
        return outter_gaps;
    case 1:
        return geometries_y(0) + triggerButtonHeight() + inner_gaps;
    default:
        return -1;
    }
}
