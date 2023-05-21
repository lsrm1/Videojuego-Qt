#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    escena = new QGraphicsScene();
    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0,0,10000,498);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    escena->setBackgroundBrush(Qt::black);

    timeanima = new QTimer();
    connect(timeanima,SIGNAL(timeout()),this,SLOT(movimiento()));
    timeanima->start(30);

    navex = new Nave;
    escena->addItem(navex);
    //navex->setFlag(QGraphicsItem::ItemIsFocusable);
    //navex->setFocus();

    Cometas.push_back(new Cometa (1000,20));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(2000,150));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(3000,200));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(4000,250));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(50000,350));
    escena->addItem(Cometas.back());
    Cometas.push_back(new Cometa(6000,400));
    escena->addItem(Cometas.back());

    timeghost = new QTimer();
    connect(timeghost,SIGNAL(timeout()),this,SLOT(Movcometa()));
    timeghost->start(50);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key() == Qt::Key_H)
        navex->MoveUp();
    if(evento->key() == Qt::Key_N)
        navex->MoveDown();
}

void MainWindow::movimiento()
{

    ui->graphicsView->centerOn(navex->posx+300,navex->posy+100);
    ui->graphicsView->setFixedSize(width(),height());

   navex->MoveRight();

    if(EvaluarColision()){
     timeanima->stop();
    timeghost->stop();}
}

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
