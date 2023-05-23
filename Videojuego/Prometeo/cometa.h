#ifndef COMETA_H
#define COMETA_H

#include <elemento.h>
class Cometa: public elemento
{
    int tipo;

public:
    Cometa(int x, int y,int _tipo);
    QRectF boundingRect() const ;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void MoveCometa();
};

#endif // COMETA_H
