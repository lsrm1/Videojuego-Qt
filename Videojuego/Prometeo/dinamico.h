#ifndef DINAMICO_H
#define DINAMICO_H


#include <QGraphicsItem>
#include <QPainter>
#include <math.h>
#include <QPixmap>

class dinamico : public QGraphicsItem
{

public:
    double x;
    double y;
    double angulo;
    float beta;
    float radio;
    float pox;
    float poy;
    float ancho;
    float alto;
    float velocidad;
    int tipomov;
    bool retro;


public:
    dinamico(double _x, double _y,double _angulo);
    dinamico(double _x, double _y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


    // Funciones mvto
    void movimiento();
    void movlineal();
};
#endif // DINAMICO_H
