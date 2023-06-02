#include "dinamico.h"

dinamico::dinamico(double _x,double _y,double _angulo)
{

    x = 0;
    y = 0;
    angulo = _angulo;
    beta = 120;
    radio=10;
    pox = _x;
    poy = _y;
    setPos(x,y);
    ancho = 50;
    alto = 54;
    tipomov = 1;

}

dinamico::dinamico(double _x, double _y)
{
    x = _x;
    y = _y;
    setPos(x,y);
    velocidad = 10;
    tipomov = 2;
    ancho = 55;
    alto = 61;
    retro = false;

}

QRectF dinamico::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void dinamico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;

    if (tipomov == 1){
    pixmap.load(":/Imagenes/obs.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());}

    if(tipomov == 2){
        pixmap.load(":/Imagenes/estatico.png");
        painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
    }
}

void dinamico::movimiento()
{
    x = pox+beta*cos(angulo);
    y = poy+beta*sin(angulo);
    angulo += 0.2 ;
    setPos(x,y);

}

void dinamico::movlineal()
{

    if (retro == false) {
        x = x + velocidad;
        setPos(x,y);
        if (x > 750)
            retro = true;
    }

    if (retro == true){
        x = x - velocidad;
        setPos(x,y);
        if (x < 20)
            retro = false;

    }
}

