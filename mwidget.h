#ifndef MWIDGET_H
#define MWIDGET_H

#include <QWidget>

class MWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MWidget(QWidget *parent = nullptr): QWidget(parent) {}
    virtual ~MWidget() {}

    virtual void setupUi(const QRect &rect) = 0;
};

#endif // MWIDGET_H
