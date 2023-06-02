#include "estatico.h"

estatico::estatico(float _x, float _y,int _tipo)
{
    posx = _x;
    posy = _y;
    tipo = _tipo;

    if (tipo == 1){
        ancho = 83;
        alto = 75;
        timee = new QTimer();
        pixmap = new QPixmap(":/Imagenes/eneria.png");
        connect(timee,&QTimer::timeout,this,&estatico::Actualizacion);
        timee->start(100);
    }

    if (tipo == 2){
        ancho = 30;
        alto = 29;
        pixmap = new QPixmap(":/Imagenes/estatic.png");
    }

    setPos(posx,posy);

}

QRectF estatico::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void estatico::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    if (tipo == 1){
        painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columna,0,ancho,alto);
    }

    if(tipo == 2){
        painter->drawPixmap(boundingRect(),*pixmap,pixmap->rect());
    }

}

void estatico::Actualizacion()
{
    columna += ancho;

    if(columna >= 410)
        columna = 0;

    this->update(-ancho/2,-alto/2,ancho,alto);
}
