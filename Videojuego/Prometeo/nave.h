#ifndef NAVE_H
#define NAVE_H

#include <elemento.h>

class Nave: public elemento
{
    QPixmap pixmap;
    //QTimer *timer;

public:
    Nave();
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void MoveUp();
    void MoveDown();
    void MoveRight();
};

#endif // NAVE_H
