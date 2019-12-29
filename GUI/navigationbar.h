#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include "mwidget.h"
#include <QPushButton>

class NavigationBar: public MWidget
{
    Q_OBJECT

public:
    explicit NavigationBar(QWidget *parent = nullptr);
    virtual ~NavigationBar();

    virtual void setupUi(const QRect &rect);

private:
    QPushButton *m_home;
    QPushButton *m_back;
};

#endif // NAVIGATIONBAR_H
