#ifndef NAVE_H
#define NAVE_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QObject>


class Nave: public QObject, public QGraphicsItem
{
public:
    int posx,posy,velocidad;
    float ancho,alto;

    QPixmap *pixmap;

public:
    Nave(QObject *parent = nullptr);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void MoveUp();
    void MoveDown();
    void MoveRight();
};

#endif // NAVE_H
