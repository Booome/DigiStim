#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include <QWidget>

class NavigationBar: public QWidget
{
public:
    explicit NavigationBar(QWidget *parent = nullptr);
    ~NavigationBar();

    void setupUi();
};

#endif // NAVIGATIONBAR_H
