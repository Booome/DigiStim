#ifndef TOPBAR_H
#define TOPBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>

class TopBar: public QWidget
{
public:
    explicit TopBar(QWidget *parent = nullptr);
    ~TopBar();

    void setupUi();

private:
    QLabel      *icon;
    QLabel      *title;
    QPushButton *setting;
};

#endif // TOPBAR_H
