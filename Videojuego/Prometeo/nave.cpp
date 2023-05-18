#include "nave.h"

Nave::Nave(QObject *parent)
{

    posy = 100;
    posx = 350;
    velocidad = 8;
    ancho = 400;
    alto = 124;
    setPos(posx,posy);

}

QRectF Nave::boundingRect() const{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void Nave::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;
    QPixmap pixmap;
    pixmap.load(":/Imagenes/nave.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}

void Nave::MoveUp(){
    posy=posy-8;
    setPos(posx, posy);
}

void Nave::MoveDown(){
    posy = posy + 8;
    setPos(posx, posy);
}

void Nave::MoveRight()
{
    posx = posx +velocidad;
    setPos(posx, posy);
}

