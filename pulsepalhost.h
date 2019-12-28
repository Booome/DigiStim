#ifndef PULSEPALHOST_H
#define PULSEPALHOST_H

#include <QObject>

class PulsePalHost : public QObject
{
    Q_OBJECT
public:
    explicit PulsePalHost(QObject *parent = nullptr);

signals:

};

#endif // PULSEPALHOST_H
