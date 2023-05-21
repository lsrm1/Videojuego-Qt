#ifndef COMETA_H
#define COMETA_H

#include <elemento.h>
class Cometa: public elemento
{

public:
    Cometa(int x, int y);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void MoveCometa();
};

#endif // COMETA_H
