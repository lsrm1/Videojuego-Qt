#include "astro.h"

astro::astro(float x, float y, float _masa, float _radio, float _vx, float _vy, int _color)
{
    posx = x;
    posy = y;
    masa = _masa;
    radio = _radio;
    vx = _vx;
    vy = _vy;
    acx = 0;
    acy = 0;
    angulo = 0;
    color = _color;
    setPos((posx/E), (-posy/E));
}

QRectF astro::boundingRect() const
{
    return QRect(-radio/ER, -radio/ER, (radio/ER)*2, (radio/ER)*2);
}

void astro::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    option = nullptr;
    widget = nullptr;

    if (color == 1) {painter->setBrush(Qt::darkGreen);painter->setPen(Qt::darkGreen);}
    if (color == 2) {painter->setBrush(Qt::white);painter->setPen(Qt::white);}
    painter->drawEllipse(boundingRect());

}

void astro::posicion()
{
    posx = posx + (vx * TI) + (0.5 * acx * pow(TI,2));
    posy = posy + (vy * TI) + (0.5 * acy * pow(TI,2));
    setPos((posx/E), (-posy/E));
}

void astro::velocidad()
{
    vx = vx + (acx*TI);
    vy = vy + (acy*TI);
}

void astro::aceleracion(float astro2, float px2, float py2)
{
    distancia = sqrt(pow((px2-posx),2) + pow((py2-posy),2));
    angulo = atan2((py2-posy),(px2-posx));
    acx += (GR * astro2 * cos(angulo)) / pow(distancia,2);
    acy += (GR * astro2 * sin(angulo)) / pow(distancia,2);
}

