#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "nave.h"
#include "cometa.h"
#include <QKeyEvent>
#include <QTimer>
#include <QPixmap>

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

private:

    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    Nave *navex;

    QString tecla;
    QList<Cometa*>Cometas;

    void keyPressEvent(QKeyEvent *evento);
    QTimer *timeanima;
    QTimer *timeghost;

    bool EvaluarColision();

};
#endif // MAINWINDOW_H
