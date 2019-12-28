#ifndef TOPBAR_H
#define TOPBAR_H

#include "mwidget.h"
#include <QLabel>
#include <QPushButton>

class TopBar: public MWidget
{
    Q_OBJECT

public:
    explicit TopBar(QWidget *parent = nullptr);
    virtual ~TopBar();

    virtual void setupUi(const QRect &rect);

private:
    QLabel      *icon;
    QLabel      *title;
    QPushButton *reset;
    QPushButton *setting;
};

#endif // TOPBAR_H
