#include "cometa.h"

Cometa::Cometa(int x, int y,int _tipo)
{
    posx = x;
    posy = y;
    tipo = _tipo;

    if (tipo == 1){
        ancho = 150;
        alto = 24;
        velocidad = 10;
    }

    if (tipo == 2){
        ancho = 60;
        alto = 53;
        velocidad = 5;
    }

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

    if (tipo == 1)
    pixmap.load(":/Imagenes/meteoro.png");


    if(tipo == 2)
        pixmap.load(":/Imagenes/aster.png");

    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());


}

void Cometa::MoveCometa()
{
    posx = posx - velocidad;
    setPos(posx, posy);
}

