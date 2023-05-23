#include "nave.h"

Nave::Nave()
{

    posy = 200;
    posx = 350;
    velocidad = 8;
    ancho = 99;
    alto = 81;

}

QRectF Nave::boundingRect() const
{
     return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Nave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    pixmap.load(":/Imagenes/nave.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}
