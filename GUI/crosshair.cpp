#include "crosshair.h"
#include <QPainter>

Crosshair::Crosshair(QWidget *parent)
    : QWidget(parent)
    , m_label(new QLabel(this))
{
}

Crosshair::~Crosshair()
{
    delete m_label;
}

void Crosshair::setupUi(const QRect &rect)
{
    setGeometry(rect);

    QPixmap pixmap(geometry().width(), geometry().height());
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);

    painter.drawLine(geometry().width() / 2,
                     0,
                     geometry().width() / 2,
                     geometry().height());

    painter.drawLine(0,
                     geometry().height() / 2,
                     geometry().width(),
                     geometry().height() / 2);

    m_label->setPixmap(pixmap);
}
