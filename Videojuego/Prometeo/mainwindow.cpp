#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    escena = new QGraphicsScene();
    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0,0,10000,700);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setMouseTracking(true);
    ui->centralwidget->setAttribute(Qt::WA_TransparentForMouseEvents);


    QPixmap fondo;
    fondo.load(":/Imagenes/mapa.png");
    ui->graphicsView->setBackgroundBrush(QBrush(fondo));

    timeanima = new QTimer();
    connect(timeanima,SIGNAL(timeout()),this,SLOT(movimiento()));
    timeanima->start(30);


    navex = new Nave;
    escena->addItem(navex);

    Cometas.push_back(new Cometa (1000,20,1));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(2000,150,1));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(3000,200,1));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(4000,250,1));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(5000,350,1));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(6000,400,1));
    escena->addItem(Cometas.back());

    Cometas.push_back(new Cometa(6000,100,2));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(3500,500,2));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(1500,400,2));
    escena->addItem(Cometas.back());

    timeghost = new QTimer();
    connect(timeghost,SIGNAL(timeout()),this,SLOT(Movcometa()));
    timeghost->start(50);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::movimiento()
{
    ui->graphicsView->centerOn(navex->posx+300,navex->posy);
    ui->graphicsView->setFixedSize(width(),height());
    navex->posx = navex->posx+navex->velocidad;
    navex->setPos(navex->posx,navex->posy);

}


//    if(EvaluarColision()){
//     timeanima->stop();
//    timeghost->stop();}


void MainWindow::Movcometa()
{

    for ( int i = 0; i < Cometas.size(); i++){

        Cometas[i]->MoveCometa();
    }

}

bool MainWindow::EvaluarColision()
{
    QList<Cometa*>::iterator it;

    for ( it = Cometas.begin(); it != Cometas.end(); it++){

        if((*it)->collidesWithItem(navex))
            return true;
    }
    return false;

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint po = event->pos();
    navex->posy=po.y();

}

