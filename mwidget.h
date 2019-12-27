#ifndef MWIDGET_H
#define MWIDGET_H

#include <QWidget>

class MWidget : public QWidget
{
public:
    explicit MWidget(QWidget *parent = nullptr);
    virtual ~MWidget();

    virtual void setupUi(const QRect &rect) = 0;
};

#endif // MWIDGET_H
