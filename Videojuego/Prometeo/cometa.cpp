#include "cometa.h"

Cometa::Cometa(int x, int y)
{
    this-> posx = x;
    this-> posy = y;
    veloci = 7;
    ancho = 489;
    alto = 78;
    setPos(posx,posy);
}

QRectF Cometa::boundingRect() const
{
     return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Cometa::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;

    QPixmap pixmap;
    pixmap.load(":/Imagenes/meteoro.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Cometa::MoveCometa()
{
    posx = posx - veloci;
    setPos(posx, posy);
}

