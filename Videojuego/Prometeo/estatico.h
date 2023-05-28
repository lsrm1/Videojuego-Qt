#ifndef ESTATICO_H
#define ESTATICO_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QTimer>

class estatico: public QGraphicsItem, public QObject
{
public:

    int posx,posy;
    float ancho,alto;
    float columna;
    int tipo;
    QTimer *timee;
    QPixmap *pixmap;

public slots:
       void Actualizacion();

public:
    estatico(float _x, float _y,int _tipo);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


#endif // ESTATICO_H
