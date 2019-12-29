#include "mainview.h"
#include "style.h"
#include <QDebug>

MainView::MainView(QWidget *parent)
    : MWidget(parent)
    , m_outter_gaps(10)
    , m_inner_gaps(5)
    , m_button_radius(20)
{
    setAttribute(Qt::WA_StyledBackground);

    for (int i = 0; i < TRIGGER_BUTTON_NUM; ++i)
        triggers[i] = new QPushButton(this);

    for (int i = 0; i < CHANNEL_BUTTON_NUM; ++i)
        channels[i] = new QPushButton(this);
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
        "QPushButton {background-color: #c6c6c6; border-top-left-radius: " + QString::number(m_button_radius) + "px; border-top-right-radius:"  + QString::number(m_button_radius) + "px;}",
        "QPushButton {background-color: #c6c6c6; border-bottom-left-radius:" + QString::number(m_button_radius) + "px; border-bottom-right-radius:" + QString::number(m_button_radius) + "px;}"
    };

    for (int i = 0; i < TRIGGER_BUTTON_NUM; ++i) {
        triggers[i]->setGeometry(geometries[i]);
        triggers[i]->setStyleSheet(styles[i]);
        triggers[i]->show();
    }
}

void MainView::setupChannels()
{
    const QRect geometries[] = {
        {geometries_x(1), geometries_y(0), channelButtonWith(), channelButtonHeight()},
        {geometries_x(1), geometries_y(1), channelButtonWith(), channelButtonHeight()},
        {geometries_x(2), geometries_y(0), channelButtonWith(), channelButtonHeight()},
        {geometries_x(2), geometries_y(1), channelButtonWith(), channelButtonHeight()}
    };

    const QString styles[] = {
        "QPushButton {background-color: #c6c6c6; border-top-left-radius: " + QString::number(m_button_radius) + "px;}",
        "QPushButton {background-color: #c6c6c6; border-bottom-left-radius: " + QString::number(m_button_radius) + "px;}",
        "QPushButton {background-color: #c6c6c6; border-top-right-radius: " + QString::number(m_button_radius) + "px;}",
        "QPushButton {background-color: #c6c6c6; border-bottom-right-radius: " + QString::number(m_button_radius) + "px;}",
    };

    for (int i = 0; i < CHANNEL_BUTTON_NUM; ++i) {
        channels[i]->setGeometry(geometries[i]);
        channels[i]->setStyleSheet(styles[i]);
        channels[i]->show();
    }
}

int MainView::triggerButtonWith()
{
    return (geometry().width() - 3 * m_outter_gaps - m_inner_gaps) / 5;
}

int MainView::triggerButtonHeight()
{
    return (geometry().height() - 2 * m_outter_gaps - m_inner_gaps) / 2;
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
        return m_outter_gaps;
    case 1:
        return geometries_x(0) + triggerButtonWith() + m_outter_gaps;
    case 2:
        return geometries_x(1) + channelButtonWith() + m_inner_gaps;
    default:
        return -1;
    }
}

int MainView::geometries_y(int row)
{
    switch (row) {
    case 0:
        return m_outter_gaps;
    case 1:
        return geometries_y(0) + triggerButtonHeight() + m_inner_gaps;
    default:
        return -1;
    }
}
