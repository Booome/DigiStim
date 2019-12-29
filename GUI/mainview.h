#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QObject>
#include "mwidget.h"
#include <QPushButton>

#define TRIGGER_BUTTON_NUM      2
#define CHANNEL_BUTTON_NUM      4

class MainView : public MWidget
{
    Q_OBJECT

public:
    explicit MainView(QWidget *parent = nullptr);
    ~MainView();

    void setupUi(const QRect &rect);

private:
    void setupTriggers();
    void setupChannels();

    int triggerButtonWith();
    int triggerButtonHeight();
    int channelButtonWith();
    int channelButtonHeight();

    int geometries_x(int cloume);
    int geometries_y(int row);

private:
    QPushButton *triggers[TRIGGER_BUTTON_NUM];
    QPushButton *channels[CHANNEL_BUTTON_NUM];

    int m_outter_gaps;
    int m_inner_gaps;
    int m_button_radius;
};

#endif // MAINVIEW_H
