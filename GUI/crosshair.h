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

    void setupUi(const QRect &rect);

private:
    QLabel *m_label;
};

#endif // CROSSHAIR_H
