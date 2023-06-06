#ifndef ASTRO_H
#define ASTRO_H

#define E 25    // Escala para los ejes
#define ER 10 // Escala para el radio
#define GR 1  // Gravedad
#define TI 1  // Variacion del tiempo

#include <QGraphicsItem>
#include <QPainter>
#include "math.h"

class astro: public QGraphicsItem
{

public:
    float posx;
    float  posy;
    float  masa;
    float  radio;
    float  vx;
    float  vy;
    float  acx;
    float  acy;
    float  angulo;
    float distancia;
    int color;

public:
    astro(float   x,  float  y, float  _masa, float  _radio, float  _vx, float  _vy, int _color);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void velocidad();
    void posicion();
    void aceleracion(float  astro2, float  px2, float py2);
};


#endif // ASTRO_H
