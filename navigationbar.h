#ifndef NAVIGATIONBAR_H
#define NAVIGATIONBAR_H

#include <QWidget>
#include <QPushButton>

class NavigationBar: public QWidget
{
public:
    explicit NavigationBar(QWidget *parent = nullptr);
    ~NavigationBar();

    void setupUi(const QRect &rect);

private:
    QPushButton *home;
    QPushButton *back;
};

#endif // NAVIGATIONBAR_H
