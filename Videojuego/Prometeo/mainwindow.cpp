#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    inicio = new QGraphicsScene();
    inicio->setSceneRect(0,0,796,792);
    QPixmap inifondo;
    inifondo.load(":/Imagenes/inicio.png");
    inicio->setBackgroundBrush(QBrush(inifondo));
    ui->graphicsView->setScene(inicio);
}

void MainWindow::jugar(){

    escena = new QGraphicsScene();
    ui->graphicsView->setScene(escena);
    escena->setSceneRect(0,0,10000,700);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setMouseTracking(true);
    ui->centralwidget->setAttribute(Qt::WA_TransparentForMouseEvents);


    QPixmap fondo;
    fondo.load(":/Imagenes/mapa.png");
    escena->setBackgroundBrush(QBrush(fondo));

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

void MainWindow::agujero()
{
    delete escena;
    timeanima->stop();
    timeghost->stop();
    //delete Cometas;

    scene = new QGraphicsScene(0, 0, 800, 3000);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    cuerp = new cuerpo(400,2970);
    scene->addItem(cuerp);
    scene->setBackgroundBrush(Qt::black);


    ui->graphicsView->centerOn(400,cuerp->y);
    ui->graphicsView->setFixedSize(800,600);

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(Actualizar()));

    time = new QTimer(this);
    connect(time,SIGNAL(timeout()), this, SLOT(Movobstaculo()));
    time->start(150);

    line = new QTimer(this);
    connect(line,SIGNAL(timeout()), this, SLOT(Movilineal()));
    line->start(70);



    obstaculo .push_back(new dinamico(200,2600,45));
    scene->addItem(obstaculo.back());
    obstaculo .push_back(new dinamico(200,2600,135));
    scene->addItem(obstaculo.back());
    obstaculo .push_back(new dinamico(200,2600,225));
    scene->addItem(obstaculo.back());

    obstaculo .push_back(new dinamico(400,2200,45));
    scene->addItem(obstaculo.back());
    obstaculo .push_back(new dinamico(400,2200,135));
    scene->addItem(obstaculo.back());
    obstaculo .push_back(new dinamico(400,2200,225));
    scene->addItem(obstaculo.back());

    lineal.push_back(new dinamico(20,1850));
    scene->addItem(lineal.back());
    lineal.push_back(new dinamico(800,1950));
    scene->addItem(lineal.back());

    lineal.push_back(new dinamico(20,1320));
    scene->addItem(lineal.back());
    lineal.push_back(new dinamico(800,1480));
    scene->addItem(lineal.back());

    eneria.push_back(new estatico(400,2200,1));
    scene->addItem(eneria.back());
    eneria.push_back(new estatico(200,2600,1));
    scene->addItem(eneria.back());
    eneria.push_back(new estatico(350,1400,1));
    scene->addItem(eneria.back());
    eneria.push_back(new estatico(300,1400,2));
    scene->addItem(eneria.back());
    eneria.push_back(new estatico(300,1450,2));
    scene->addItem(eneria.back());
    eneria.push_back(new estatico(350,1450,2));
    scene->addItem(eneria.back());
    eneria.push_back(new estatico(400,1450,2));
    scene->addItem(eneria.back());
    eneria.push_back(new estatico(350,1450,2));
    scene->addItem(eneria.back());
    eneria.push_back(new estatico(400,1450,2));
    scene->addItem(eneria.back());
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

    if (navex->posx>9950){
        agujero();

    }

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

//bool MainWindow::EvaluarColision()
//{
//    QList<Cometa*>::iterator it;

//    for ( it = Cometas.begin(); it != Cometas.end(); it++){

//        if((*it)->collidesWithItem(navex))
//            return true;
//    }
//    return false;

//}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint po = event->pos();
    navex->posy=po.y();

}


void MainWindow::on_play_clicked()
{
    ui->play->setVisible(false);
    jugar();
}

void MainWindow::keyPressEvent(QKeyEvent *evento)
{

    timer->start(30);
    if(evento->key() == Qt::Key_M ) direccion = "M";
    else if(evento->key() == Qt::Key_B) direccion = "B";

    nux = cuerp->getX();
    nuy = cuerp->getY();

    scene->removeItem(cuerp);
    delete cuerp;

    cuerp = new cuerpo(nux, nuy);
    scene->addItem(cuerp);

}


void MainWindow::vista()
{
    if (cuerp->y > 2400)
        ui->graphicsView->centerOn(400,2800);

    if ((cuerp->y < 2400) &&(cuerp->y >1800))
        ui->graphicsView->centerOn(400,2100);

    if ((cuerp->y < 1800) &&(cuerp->y > 1200))
        ui->graphicsView->centerOn(400,1500);

    if ((cuerp->y < 1200) &&(cuerp->y > 600))
        ui->graphicsView->centerOn(400,900);

    if ((cuerp->y < 600) &&(cuerp->y > 0))
        ui->graphicsView->centerOn(400,300);


}


void MainWindow::Actualizar()
{

    cuerp->velocidades();
    cuerp->posiciones(direccion);
    vista();
    if(cuerp->y>2970)
         timer->stop();

//    if(EvaluarColision1()){
//        timer->stop();
//        time->stop();
//        line->stop();
//    }

//    if(EvaluarColision2()){
//        timer->stop();
//        time->stop();
//        line->stop();
//    }

}

void MainWindow::Movobstaculo()
{
    QList<dinamico*>::iterator it;

    for ( it = obstaculo.begin(); it != obstaculo.end(); it++)
        (*it)->movimiento();
}

void MainWindow::Movilineal()
{
    QList<dinamico*>::iterator i;

    for ( i = lineal.begin(); i != lineal.end(); i++)
        (*i)->movlineal();

}



//bool MainWindow::EvaluarColision1(){
//    QList<dinamico*>::iterator it;

//    for ( it = obstaculo.begin(); it != obstaculo.end(); it++)  {
//        if((*it)->collidesWithItem(cuerp))
//            return true;

//    }
//    return false;
//}

//bool MainWindow::EvaluarColision2()
//{
//    QList<dinamico*>::iterator i;
//    for ( i = lineal.begin(); i != lineal.end(); i++){
//        if((*i)->collidesWithItem(cuerp))
//            return true;
//    }
//    return false;
//}


