#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QTimer>
#include <QPixmap>
#include <QMouseEvent>
#include <QList>
#include "nave.h"
#include "cometa.h"
#include "cuerpo.h"
#include "dinamico.h"
#include "estatico.h"

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

    QString direccion;

    QList<Cometa*>Cometas;
    QList<estatico*> eneria;
    QList<dinamico*> obstaculo;
    QList<dinamico*> lineal;



    float nux;
    float nuy;

    bool EvaluarColision();
    void jugar();
    void agujero();


    void mouseMoveEvent(QMouseEvent *event);    
    void keyPressEvent(QKeyEvent *evento);
    bool EvaluarColision1();
    bool EvaluarColision2();
    void vista ();


};
#endif // MAINWINDOW_H
