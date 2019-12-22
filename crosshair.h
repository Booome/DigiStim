#ifndef CROSSHAIR_H
#define CROSSHAIR_H

#include <QWidget>
#include <QLabel>

class Crosshair : public QWidget
{
    Q_OBJECT
public:
    explicit Crosshair(QWidget *parent = nullptr);
    ~Crosshair();

    void setupUi();

private:
    QLabel *label;
};

#endif // CROSSHAIR_H
