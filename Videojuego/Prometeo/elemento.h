#ifndef ELEMENTO_H
#define ELEMENTO_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>
#include <QObject>

class elemento :public QGraphicsItem,public QObject
{

    public:
        int posx,posy,velocidad;
        float ancho,alto;
        float columna;

    public:
        elemento();
};
#endif // ELEMENTO_H
