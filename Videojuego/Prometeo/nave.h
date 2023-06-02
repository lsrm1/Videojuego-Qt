#ifndef NAVE_H
#define NAVE_H

#include <elemento.h>

class Nave: public elemento
{
    QPixmap *pixmap;

public:
    Nave();
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void destruir();
};

#endif // NAVE_H
