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

    if (tipo == 3){
        ancho = 250;
        alto = 214;
        pixmap = new QPixmap(":/Imagenes/exit.jpg");
        timee = new QTimer();
        connect(timee,&QTimer::timeout,this,&estatico::Actualizacion);
        timee->start(100);
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

    if(tipo == 3){
        painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columna,0,ancho,alto);
    }

}

void estatico::Actualizacion()
{
    columna += ancho;

    if(columna >= ancho*4)
        columna = 0;

    this->update(-ancho/2,-alto/2,ancho,alto);
}
