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
    ui->graphicsView->setFixedSize(800,800);
    inifondo.load(":/Imagenes/inicio.png");
    inicio->setBackgroundBrush(QBrush(inifondo));
    ui->graphicsView->setScene(inicio);

    ui->lcdNumber->setVisible(false);


    reinicio = new QTimer();
    connect(reinicio,SIGNAL(timeout()),this,SLOT(jugar()));

    reinicio2 = new QTimer();
    connect(reinicio2,SIGNAL(timeout()),this,SLOT(agujero()));

    choque = false;
    choque2 = false;
}

void MainWindow::on_play_clicked()
{
    ui->play->setVisible(false);
    jugar();
}


void MainWindow::jugar(){

    if(choque){

        choque = false;
        reinicio->stop();
        timeanima->stop();
        timeghost->stop();
        escena->removeItem(navex);
        delete navex;
        delete timeanima;
        delete timeghost;

        for (int t = 0; t < Cometas.size(); t++)
               escena->removeItem(Cometas[t]);

        Cometas.clear();
        delete escena;

    }

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

    navex = new Nave;
    escena->addItem(navex);

    Crearcometas();
    timeanima = new QTimer();
    connect(timeanima,SIGNAL(timeout()),this,SLOT(movimiento()));
    timeanima->start(30);

    timeghost = new QTimer();
    connect(timeghost,SIGNAL(timeout()),this,SLOT(Movcometa()));
    timeghost->start(50);


}

void MainWindow::movimiento()
{
    ui->graphicsView->centerOn(navex->posx+300,navex->posy);
    ui->graphicsView->setFixedSize(width(),height());
    navex->posx = navex->posx+navex->velocidad;
    navex->setPos(navex->posx,navex->posy);

    if(Colisioncometa()){
        navex->destruir();
        choque = true;
        reinicio->start(2000);

    }

    if (navex->posx>9350){

        timeanima->stop();
        timeghost->stop();
        escena->removeItem(navex);
        delete navex;
        delete timeanima;
        delete timeghost;

        for (int t = 0; t < Cometas.size(); t++)
               escena->removeItem(Cometas[t]);

        Cometas.clear();
        delete escena;
        agujero();
    }

}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint po = event->pos();
    navex->posy=po.y();

}

void MainWindow::Crearcometas() // Recibe un txt con posiciones
{
    ifstream obs;
    int x, y,z;
    obs.open("cometa.txt");

    while (obs.good()){

        obs >> x;
        obs >> y;
        obs >> z;

        Cometas.push_back(new Cometa(x,y,z));
        escena->addItem(Cometas.back());
    }
    obs.close();
}


bool MainWindow::Colisioncometa()
{
    QList<Cometa*>::iterator it;

    for ( it = Cometas.begin(); it != Cometas.end(); it++){

        if((*it)->collidesWithItem(navex))
            return true;
    }
    return false;

}

void MainWindow::Movcometa()
{

    for ( int h = 0; h < Cometas.size(); h++)
        Cometas[h]->MoveCometa();

}

//----------------------------------------------------------------------------------------------------------------------------------------------//

void MainWindow::agujero()
{
    if(choque2){

        choque2 = false;
        reinicio2->stop();

        scene->removeItem(cuerp);
        delete cuerp;
        delete timer;
        delete time;
        delete line;


        for (int t = 0; t < obstaculo.size(); t++)
               scene->removeItem(obstaculo[t]);

        for (int t = 0; t < lineal.size(); t++)
               scene->removeItem(lineal[t]);

        for (int t = 0; t < eneria.size(); t++)
               scene->removeItem(eneria[t]);

        for (int t = 0; t < tesse.size(); t++)
               scene->removeItem(tesse[t]);

        obstaculo.clear();
        lineal.clear();
        eneria.clear();
        tesse.clear();

        delete scene;

    }


        scene = new QGraphicsScene;
        ui->graphicsView->setScene(scene);
        scene->setSceneRect(0, 0, 800, 3000);
        ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        cuerp = new cuerpo(400,2940);
        scene->addItem(cuerp);
        scene->setBackgroundBrush(Qt::black);

        ui->graphicsView->centerOn(400,cuerp->y);
        ui->graphicsView->setFixedSize(1400,600);


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

        tesse.push_back(new estatico(400,2200,1));
        scene->addItem(tesse.back());
        tesse.push_back(new estatico(200,2600,1));
        scene->addItem(tesse.back());
        tesse.push_back(new estatico(350,1400,1));
        scene->addItem(tesse.back());


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
        eneria.push_back(new estatico(400,200,2));
        scene->addItem(eneria.back());



        timer = new QTimer(this);
        connect(timer,SIGNAL(timeout()), this, SLOT(Actualizar()));

        time = new QTimer(this);
        connect(time,SIGNAL(timeout()), this, SLOT(Movobstaculo()));
        time->start(150);

        line = new QTimer(this);
        connect(line,SIGNAL(timeout()), this, SLOT(Movilineal()));
        line->start(70);

        ui->lcdNumber->setVisible(true);
        tesses = tesse.size();
        ui->lcdNumber->display(tesses);
}

MainWindow::~MainWindow()
{
    delete ui;
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

    if(cuerp->y>2950)
         timer->stop();

    if (EvaluarColision1()) {
        choque2 = true;
        timer->stop();
        time->stop();
        line->stop();
        reinicio2->start(2000);
    }

    if (EvaluarColision2()) {
        choque2 = true;
        timer->stop();
        time->stop();
        line->stop();
        reinicio2->start(2000);
    }

    if (EvaluarColision3()) {
        choque2 = true;
        timer->stop();
        time->stop();
        line->stop();
        reinicio2->start(2000);
    }

    if (EvaluarColision4()) {

        tesses = tesse.size();
        ui->lcdNumber->display(tesses);

    }

    if(cuerp->y<200){

       if (tesse.size() == 0){

            QMessageBox::critical(this,"Aviso","Misión completa!!");
            timer->stop();
            time->stop();
            line->stop();

        }



    }



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

bool MainWindow::EvaluarColision1(){
    QList<dinamico*>::iterator it;

    for ( it = obstaculo.begin(); it != obstaculo.end(); it++)  {
        if((*it)->collidesWithItem(cuerp))
            return true;

    }
    return false;
}

bool MainWindow::EvaluarColision2()
{
    QList<dinamico*>::iterator i;
    for ( i = lineal.begin(); i != lineal.end(); i++){
        if((*i)->collidesWithItem(cuerp))
            return true;
    }
    return false;
}

bool MainWindow::EvaluarColision3()
{
    QList<estatico*>::iterator h;
    for ( h = eneria.begin(); h != eneria.end(); h++){
        if((*h)->collidesWithItem(cuerp))
            return true;
    }
    return false;
}

bool MainWindow::EvaluarColision4()
{

    for (int in = 0 ; in < tesse.size();in++) {

           if(cuerp->collidesWithItem(tesse.at(in))){

               scene->removeItem(tesse.at(in));
               tesse.removeAt(in);
                return true;
        }
    }
    return false;
}



