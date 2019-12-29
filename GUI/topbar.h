#ifndef TOPBAR_H
#define TOPBAR_H

#include "mwidget.h"
#include <QLabel>
#include <QPushButton>
#include "diginamespace.h"

class TopBar: public MWidget
{
    Q_OBJECT

public:
    explicit TopBar(QWidget *parent = nullptr);
    virtual ~TopBar();

    virtual void setupUi(const QRect &rect);

private:
    void setupIcon();
    void setupTitle();
    void setupConnState();
    void setupDevName();
    void setupReset();
    void setupSetting();

public slots:
    void on_connStateChange(Digi::ConnectState_t);
    void on_devNameChange(const QString &dev);

private:
    QLabel      *m_icon;
    QLabel      *m_title;
    QLabel      *m_conn_state;
    QPushButton *m_dev_name;
    QPushButton *m_reset;
    QPushButton *m_setting;
};

#endif // TOPBAR_H
