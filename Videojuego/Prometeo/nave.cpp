#include "nave.h"

Nave::Nave()
{

    posy = 200;
    posx = 350;
    velocidad = 10;
    ancho = 99;
    alto = 81;
    pixmap = new QPixmap;
    pixmap->load(":/Imagenes/nave.png");

}

QRectF Nave::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Nave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect());
}

void Nave::destruir()
{
    pixmap->load(":/Imagenes/colision.png");
}
