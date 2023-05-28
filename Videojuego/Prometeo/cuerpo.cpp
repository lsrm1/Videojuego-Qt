#include "cuerpo.h"

cuerpo::cuerpo(QObject *parent)
{


}

cuerpo::cuerpo(float _x, float _y)
{
    x = _x;
    y = _y;
    vx = 20;
    vy = 50;
    ax = 1;
    ay = GRAV;
    radio = 10;
    setPos(x,y);

    ancho = 40;
    alto = 40;
    //timer = new QTimer(this);
    //filas = 0;
    //columnas = 0;
    //pixmap = new QPixmap(":/cuerpo.png");
    //connect(timer,&QTimer::timeout,this,&cuerpo::Actualizacion);
    //timer->start(300);
}

QRectF cuerpo::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void cuerpo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //painter->setBrush(Qt::darkGreen);
    //painter->drawEllipse(boundingRect());
    //painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
    QPixmap pixmap;
    pixmap.load(":/cuerpo.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}



float cuerpo::getX() const
{
    return x;
}
float cuerpo::getY() const
{
    return y;
}

void cuerpo::velocidades()
{
    vx = vx + (ax*DT);
    vy = vy + (ay*DT);

}

void cuerpo::posiciones(QString direccion)
{
    if (direccion == "M")
        x = (x + (vx * DT) + (0.5 * ax * pow(DT,2)));

    if (direccion == "B")
        x = (x + (-vx * DT) + (0.5 * ax * pow(DT,2)));

    y = (y + (-vy * DT) + (0.5 * ay * pow(DT,2)));
    setPos(x,y);

}
