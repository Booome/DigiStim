#ifndef MYAPPLICATION_H
#define MYAPPLICATION_H

#include <QApplication>

class MyApplication : public QApplication
{
public:
    MyApplication(int &argc, char **argv);

    ~MyApplication();

    bool eventFilter(QObject *watched, QEvent *event);
};

#endif // MYAPPLICATION_H
