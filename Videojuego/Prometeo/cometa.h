#ifndef COMETA_H
#define COMETA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

class Cometa: public QGraphicsItem
{
    int posx;
    int posy;
    float ancho,alto;
    int veloci;

public:
    Cometa(int x, int y);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void MoveCometa();
};

#endif // COMETA_H
