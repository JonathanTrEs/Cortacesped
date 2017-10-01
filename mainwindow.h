#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include "pixmap_click.h"
#include <unistd.h>
#include <QPoint>
#include <QTimer>
#include <cmath>
#include <QtAlgorithms>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_resize_clicked();
    void click_mod(void * , bool b);
    void on_Slider_sliderMoved(int position);
    void on_Slider_valueChanged(int value);
    void on_alto_returnPressed();
    void dfs();
    void aestrella();

    void on_pushButton_clicked();
    void on_start_clicked();

signals:
    void sign_slider(int);
    void enter();
    void timeout();
    void timeout2();

private:

    void Dibujar();
    void Refrescar(bool, QPoint);
    void Cuadricula();

    Ui::MainWindow *ui;
    QGraphicsScene *scene;

    //Datos de estado.
    char ** Matrix;

    //Matriz de visitados
    bool ** Visitados;

    //Dimensiones
    int n;
    int m;

    //Constante tamaño de imagen
    int L;

    //Probabilidad de obstaculos
    int P;

    //Imagenes de casillas
    QPixmap *imCa;//Cesped alto
    QPixmap *imCb;//Cesped bajo
    QPixmap *imO;//Obstaculo
    QPixmap *imA;//Agente

    QPoint p;//Punto de partida del agente.


    QTimer *timer;//Timer
    QTimer *timerA;


    //a*


    QPoint d;//Punto destino.
    QPoint ini; //Punto inicio.
    QList<QPoint> pila;
    double manhattan(QPoint,QPoint);

};



#endif // MAINWINDOW_H
