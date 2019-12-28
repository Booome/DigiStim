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
    QLabel      *icon;
    QLabel      *title;
    QLabel      *conn_state;
    QPushButton *dev_name;
    QPushButton *reset;
    QPushButton *setting;
};

#endif // TOPBAR_H
