#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>

class TopBar: public QWidget
{
public:
    explicit TopBar(QWidget *parent = nullptr);
    ~TopBar();
};

#endif // TOPBAR_H
