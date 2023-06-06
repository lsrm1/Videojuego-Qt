#ifndef CUERPO_H
#define CUERPO_H


#define GRAV -9.8
#define DT 0.25

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include <QTimer>

class cuerpo : public QGraphicsItem, public QObject
{

public:
    float x, y, vx, vy, ax, ay, radio;

    float ancho,alto;
    float filas,columnas;

    QPixmap *pixmap2;

public:
    cuerpo(float _x, float _y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    // get
    float getX() const;
    float getY() const;

    // Funciones mvto
    void velocidades();
    void posiciones(QString direccion);
    void destruir();
};

#endif // CUERPO_H
