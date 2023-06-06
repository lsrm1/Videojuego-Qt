#include "cuerpo.h"

cuerpo::cuerpo(float _x, float _y)
{
    x = _x;
    y = _y;
    vx = 20;
    vy = 50;
    ax = 1;
    ay = GRAV;
    radio = 10;
    setPos(x,y);
    pixmap2 = new QPixmap;
    pixmap2->load(":/Imagenes/cuerpo.png");

    ancho = 40;
    alto = 40;

}

QRectF cuerpo::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(boundingRect(),*pixmap2,pixmap2->rect());
}



float cuerpo::getX() const
{
    return x;
}
float cuerpo::getY() const
{
    return y;
}

void cuerpo::velocidades()
{
    vx = vx + (ax*DT);
    vy = vy + (ay*DT);

}

void cuerpo::posiciones(QString direccion)
{
    if (direccion == "M")
        x = (x + (vx * DT) + (0.5 * ax * pow(DT,2)));

    if (direccion == "B")
        x = (x + (-vx * DT) + (0.5 * ax * pow(DT,2)));

    y = (y + (-vy * DT) + (0.5 * ay * pow(DT,2)));
    setPos(x,y);

}

void cuerpo::destruir()
{
    ancho = 110;
    alto = 116;
    pixmap2->load(":/Imagenes/explota.png");
}

