#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QPixmap>
#include <QMouseEvent>
#include <QList>
#include <fstream>
#include <QMessageBox>
#include "nave.h"
#include "cometa.h"
#include "cuerpo.h"
#include "dinamico.h"
#include "estatico.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



public slots:

    void movimiento();
    void Movcometa();
    void Actualizar();
    void Movobstaculo();
    void Movilineal();
    void jugar();
    void agujero();


private slots:
    void on_play_clicked();

private:

    Ui::MainWindow *ui;

    QGraphicsScene *escena;
    QGraphicsScene *inicio;
    QGraphicsScene *scene;

    Nave *navex;
    cuerpo *cuerp;

    QTimer *timer;
    QTimer *time;
    QTimer *line;
    QTimer *timeanima;
    QTimer *timeghost;
    QTimer *reinicio;
    QTimer *reinicio2;


    QString direccion;
    int tesses;

    QList<Cometa*>Cometas;
    QList<estatico*> eneria;
    QList<estatico*> tesse;
    QList<dinamico*> obstaculo;
    QList<dinamico*> lineal;

    float nux;
    float nuy;

    bool Colisioncometa();

    bool choque;
    bool choque2;



    void mouseMoveEvent(QMouseEvent *event);    
    void keyPressEvent(QKeyEvent *evento);
    bool EvaluarColision1();
    bool EvaluarColision2();
    bool EvaluarColision3();
    bool EvaluarColision4();
    void vista ();
    void Crearcometas();



};
#endif // MAINWINDOW_H
