#include "myapplication.h"
#include <QDebug>

MyApplication::MyApplication(int &argc, char **argv)
    : QApplication(argc, argv)
{
}

MyApplication::~MyApplication()
{
}

bool MyApplication::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonPress)
        qDebug() << watched->metaObject()->className()
                 << event->type();
    else if (event->type() == QEvent::MouseButtonRelease)
        qDebug() << watched->metaObject()->className()
                 << event->type();

    return QApplication::eventFilter(watched, event);
}
