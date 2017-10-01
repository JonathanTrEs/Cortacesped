#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene ();
    ui->graphicsView->setScene(scene);

    //qRegisterMetaType< QVector<QPoint*> >("QVector<QPoint*>");

    L = 50; //Determinar tamño imagen.

    QPixmap aux1 ("imCa.jpg");
    QPixmap aux2 ("imCb.jpg");
    QPixmap aux3 ("imA.jpg");
    QPixmap aux4 ("imO.jpg");

    aux1 = aux1.scaled(L,L,Qt::IgnoreAspectRatio,Qt::FastTransformation);
    aux2 = aux2.scaled(L,L,Qt::IgnoreAspectRatio,Qt::FastTransformation);
    aux3 = aux3.scaled(L,L,Qt::IgnoreAspectRatio,Qt::FastTransformation);
    aux4 = aux4.scaled(L,L,Qt::IgnoreAspectRatio,Qt::FastTransformation);

    imCa = new QPixmap (aux1);
    imCb = new QPixmap (aux2);
    imA = new QPixmap (aux3);
    imO = new QPixmap (aux4);



    ui->Slider->setMaximum(75);
    ui->Slider->setMinimum(1);

    timer = new QTimer(this);
     timerA = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(dfs()));
    connect(timerA,SIGNAL(timeout()),this,SLOT(aestrella()));

    QObject::connect(this,SIGNAL(sign_slider(int)),this,SLOT(on_Slider_valueChanged(int)) );
    QObject::connect(this,SIGNAL(enter()),this,SLOT(on_resize_clicked()));

    //a*


}

MainWindow::~MainWindow()
{
    delete ui;
    //Destruir la matriz de char.
}

//Boton resize slot
void MainWindow::on_resize_clicked()
{
    pila.clear();
    timerA->stop();
    if(ui->alto->text().toInt() > 0) {

        n=ui->alto->text().toInt();
        m=ui->ancho->text().toInt();
        ini.setX(ui->y1->text().toInt());
        ini.setY(ui->x1->text().toInt());
        d.setX(ui->y2->text().toInt());
        d.setY(ui->x2->text().toInt());
        p.setX(ini.x());
        p.setY(ini.y());

        //Redimensionar

        Matrix = new char * [n];
        for(int i=0;i<n;i++)
            Matrix[i]= new char[m];

        Visitados = new bool * [n];
        for(int i=0;i<n;i++)
            Visitados[i]= new bool[m];

        //Cálculo N Obstáculos

        double op = static_cast<double>(P) / 100;

        op=n*m*op;
        int redondeo=(int)(op);

        qDebug() << "n elementos" << redondeo;

        int i,j,k;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                Visitados[i][j]=false;

        while (redondeo!=0){
            i=qrand()%n;
            j=qrand()%m;
            Matrix[i][j]='o';
            Visitados[i][j]=true;
            --redondeo;
        }

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(Matrix[i][j]!='o'){
                    k=qrand()%3;
                    if(k==0)
                        Matrix[i][j]='b';
                    else
                        Matrix[i][j]='a';

                }


        Matrix[p.x()][p.y()]='A';

        //Reset Anteriores
        pila.clear();

        //Reset Timer
        timer->stop();

        Dibujar();

    }
    else
        QMessageBox::information(this,"ERROR","Introduce un valor numérico positivo.");

}

//Actualizacion de la interfaz.
//b hierba baja objeto pixmap_click
//a hierba alta objeto pixmap_click
//o obstaculo          pixmap_click
//A agente             QGraphicsPixmapItem

//Imprime cuadricula sobre todas las imagenes

//todas las imagenes declaradas como pixmap_click
//Estan atendiendo a que haya un click sobre ellas

//Para ello
//Conecto la señal del objeto canal con el slot de la clase this
//Para que cuando la funcion mousePressEvent de la clase pixmap_click
//Se comunique ante un cambio con el slot click_mod por la señal del objeto canal

void MainWindow::Dibujar(){

    scene->deleteLater();
    scene = new QGraphicsScene(this);


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            switch (Matrix[i][j]){
            case 'a':{
                pixmap_click * pix = new pixmap_click ();
                pix->setPixmap(*imCa);
                QObject::connect(pix->canal,SIGNAL(mousePressed(void *,bool)),this,SLOT(click_mod(void *,bool)));
                scene->addItem(pix);
                pix->setX(L*i);
                pix->setY(L*j);

            }
            break;
            case 'b':{
                pixmap_click * pix = new pixmap_click ();
                pix->setPixmap(*imCb);
                QObject::connect(pix->canal,SIGNAL(mousePressed(void *,bool)),this,SLOT(click_mod(void *,bool)));
                scene->addItem(pix);
                pix->setX(L*i);
                pix->setY(L*j);
            }
            break;
            case 'o':{
                pixmap_click * pix = new pixmap_click ();
                pix->setPixmap(*imO);
                QObject::connect(pix->canal,SIGNAL(mousePressed(void *,bool)),this,SLOT(click_mod(void *,bool)));
                scene->addItem(pix);
                pix->setX(L*i);
                pix->setY(L*j);
            }
            break;
            case 'A':{
                QGraphicsPixmapItem * pt3 = scene->addPixmap(*imA);
                pt3->setX(L*i);
                pt3->setY(L*j);
                ui->graphicsView->centerOn(i*L,j*L);
            }
            break;
            default: qDebug() << "Fallo carga imagen, no caracter valido";
            }
        }
    }

    Cuadricula();

    ui->graphicsView->setScene(scene);
    ui->graphicsView->show();
}

//Sobrecarga para clicks
//b->a->o
//creo objeto pixmap_click
//Y decodificar las coordenadas del evento QGraphicsSceneMouseEvent
//Presente en cada uno de los objetos creados dentro de esta funcion (pixmap_click)
void MainWindow::click_mod(void * canal,bool b)
{
    //Transforma el void* de los parametros a pixmap_item
    //Luego saca las coordenadas

    if (!timer->isActive()) {
    pixmap_click * item = reinterpret_cast<pixmap_click *>(canal);

    int i= static_cast<int>(item->x()/L);
    int j= static_cast<int>(item->y()/L);

    switch (Matrix[i][j]) {
    case 'b':{
        if(b){
            Matrix[i][j]='a';
            item->setPixmap(*imCa);
        }else{
            d.setX(i);
            d.setY(j);
        }
    }
    break;
    case 'a':{
        if(b){
            Matrix[i][j]='o';
            item->setPixmap(*imO);
            Visitados[i][j]=true;
        }
        else{
            d.setX(i);
            d.setY(j);
        }
    }
    break;
    case 'o':{
        Matrix[i][j]='b';
        item->setPixmap(*imCb);
        Visitados[i][j]=false;
    }
    break;
    default: qDebug() << "fallo lectura array caracteres";
    }
    qDebug() << d.x() << " " << d.y();
}
}

//Pintar rectas forma de reja horizontal y vertical.
void MainWindow::Cuadricula(){

    QPen blackPen(Qt::black);

    blackPen.setWidth(1);


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scene->addRect(i*L,j*L,L,L,blackPen);
        }
    }
}

void MainWindow::on_Slider_sliderMoved(int position)
{

    emit sign_slider(position);

}



void MainWindow::on_Slider_valueChanged(int value)
{
    QString a = QString::number(value);
    QString b ("%");


    P=value;

    ui->v_slider->setText(a+b);
}

void MainWindow::on_start_clicked()
{

    timer->start(0);

}

void MainWindow::on_alto_returnPressed()
{
    emit(enter());
}


void MainWindow::dfs(){
    //x+1 y derecha
    //x-1 y izquierda
    //y+1 abajo
    //y-1 arriba
    QPoint viejo;
    bool donde = true;

        if(p.x()+1 < n && Visitados[p.x()+1][p.y()]==false) //Movimiento Derecha
        {
            //Puedes moverte? (RANGO, VISITADO?)
            //Cortar Césped
            viejo.setX(p.x());
            viejo.setY(p.y());
            Matrix[p.x()][p.y()]='b';
            Visitados[p.x()][p.y()]=true;
            //Guardar como anterior
            pila.push_back(p);

            //Moverse
            p.rx()++;
            Matrix[p.x()][p.y()]='A';
            qDebug () << "Derecha";

        }
        else if(p.y()+1 < m && Visitados[p.x()][p.y()+1]==false) //Movimiento Abajo
        {
            //Puedes moverte? (RANGO, VISITADO?)
            //Cortar Césped
            viejo.setX(p.x());
            viejo.setY(p.y());
            Matrix[p.x()][p.y()]='b';
            Visitados[p.x()][p.y()]=true;
            //Guardar como anterior
            pila.push_back(p);

            //Moverse
            p.ry()++;
            Matrix[p.x()][p.y()]='A';
            qDebug()<< "Abajo";
        }
        else if(p.x()-1 >= 0 && Visitados[p.x()-1][p.y()]==false) //Movimiento Izquierda
        {
            //Puedes moverte? (RANGO, VISITADO?)
            //Cortar Césped
            viejo.setX(p.x());
            viejo.setY(p.y());
            Matrix[p.x()][p.y()]='b';
            Visitados[p.x()][p.y()]=true;
            //Guardar como anterior
            pila.push_back(p);

            //Moverse
            p.rx()--;
            Matrix[p.x()][p.y()]='A';


            qDebug() << "Izquierda";
        }
        else if(p.y()-1 >= 0 && Visitados[p.x()][p.y()-1]==false) //Movimiento Arriba
        {
            //Puedes moverte? (RANGO, VISITADO?)
            //Cortar Césped
            viejo.setX(p.x());
            viejo.setY(p.y());
            Matrix[p.x()][p.y()]='b';
            Visitados[p.x()][p.y()]=true;
            //Guardar como anterior
            pila.push_back(p);

            //Moverse
            p.ry()--;
            Matrix[p.x()][p.y()]='A';

            qDebug() << "Arriba" << Matrix[p.x()][p.y()];
            qDebug() << "Arriba" << Matrix[p.x()][p.y()+1];
        }
        else if(!pila.isEmpty()){
            viejo.setX(p.x());
            viejo.setY(p.y());
            Matrix[p.x()][p.y()]='b';
            Visitados[p.x()][p.y()]=true;
            pila.back();
            p.rx() = pila.back().x();
            p.ry() = pila.back().y();
            Matrix[p.x()][p.y()]='A';
            pila.pop_back();
            donde = true;
            if(pila.isEmpty())
            {
                emit(timeout());
            }

        }

        Refrescar(donde,viejo);
        qDebug() << pila.size();




}
void MainWindow::Refrescar(bool donde, QPoint viejo)
{
    if(!donde)
    {
        QGraphicsPixmapItem * pt3 = scene->addPixmap(*imA);
        pt3->setX(L*p.x());
        pt3->setY(L*p.y());
        ui->graphicsView->centerOn(p.x()*L,p.y()*L);

        pixmap_click * pix = new pixmap_click ();
        pix->setPixmap(*imCb);
        QObject::connect(pix->canal,SIGNAL(mousePressed(void *,bool)),this,SLOT(click_mod(void *,bool)));
        scene->addItem(pix);
        pix->setX(L*viejo.x());
        pix->setY(L*viejo.y());
    }
    else if(donde)
    {
        QGraphicsPixmapItem * pt3 = scene->addPixmap(*imA);
        pt3->setX(L*p.x());
        pt3->setY(L*p.y());
        ui->graphicsView->centerOn(p.x()*L,p.y()*L);

        pixmap_click * pix = new pixmap_click ();
        pix->setPixmap(*imCb);
        QObject::connect(pix->canal,SIGNAL(mousePressed(void *,bool)),this,SLOT(click_mod(void *,bool)));
        scene->addItem(pix);
        pix->setX(L*viejo.x());
        pix->setY(L*viejo.y());
    }


}

void MainWindow::on_pushButton_clicked()
{
 timerA->start(100);
}

void MainWindow::aestrella()
{
    QPoint viejo;
    double menor = -1;
    char mov = ' ';
    bool donde = true;
    if((ini.x() == d.x() && ini.y() == d.y())
            || (p.x() == d.x() && p.y() == d.y()))
    {
        qDebug() << "Acabado" << p.x() << " " << p.y();
        emit(timeout());

    }
    else {
        if(p.x()+1 < n && Visitados[p.x()+1][p.y()]==false) {//Movimiento a la derecha
            QPoint temp;
            temp.setX(p.x()+1);
            temp.setY(p.y());
            menor = manhattan(temp,d);
            mov = 'D';
        }
        if(p.y()+1 < m && Visitados[p.x()][p.y()+1]==false) { //Movimiento Abajo
            QPoint temp;
            temp.setX(p.x());
            temp.setY(p.y()+1);
            if(menor == -1 || manhattan(temp,d) < menor){
                menor = manhattan(temp,d);
                mov = 'B';
            }
        }
        if(p.x()-1 >= 0 && Visitados[p.x()-1][p.y()]==false) { //Movimiento Izquierda
            QPoint temp;
            temp.setX(p.x()-1);
            temp.setY(p.y());
            if(menor == -1 || manhattan(temp,d) < menor){
                menor = manhattan(temp,d);
                mov = 'I';
            }
        }
        if(p.y()-1 >= 0 && Visitados[p.x()][p.y()-1]==false) { //Movimiento Arriba
            QPoint temp;
            temp.setX(p.x());
            temp.setY(p.y()-1);
            if(menor == -1 || manhattan(temp,d) < menor){
                menor = manhattan(temp,d);
                mov = 'A';
            }
        }
        if(menor == -1)
        {
            if(pila.isEmpty())
            {
                qDebug() << "Tupac";
                emit(timeout());
            }
            else{
                viejo.setX(p.x());
                viejo.setY(p.y());
                Matrix[p.x()][p.y()]='b';
                Visitados[p.x()][p.y()]=true;
                p = pila.back();
                Matrix[p.x()][p.y()]='A';
                qDebug() << pila.size();
                pila.pop_back();
                donde = true;
            }
        }
        else{
            if(mov == 'D'){
                //Cortar Césped
                Matrix[p.x()][p.y()]='b';
                Visitados[p.x()][p.y()]=true;
                //Guardar como anterior
                viejo.setX(p.x());
                viejo.setY(p.y());
                pila.push_back(p);

                //Moverse
                p.rx()++;
                Matrix[p.x()][p.y()]='A';
                qDebug () << "Derecha";
            }
            else if(mov == 'B'){
                //Cortar Césped
                Matrix[p.x()][p.y()]='b';
                Visitados[p.x()][p.y()]=true;
                //Guardar como anterior
                viejo.setX(p.x());
                viejo.setY(p.y());
                pila.push_back(p);

                //Moverse
                p.ry()++;
                Matrix[p.x()][p.y()]='A';
                qDebug()<< "Abajo";
            }
            else if(mov == 'I'){
                //Cortar Césped
                Matrix[p.x()][p.y()]='b';
                Visitados[p.x()][p.y()]=true;
                //Guardar como anterior
                viejo.setX(p.x());
                viejo.setY(p.y());
                pila.push_back(p);

                //Moverse
                p.rx()--;
                Matrix[p.x()][p.y()]='A';
                qDebug()<< "Izquierda";
            }
            else if(mov == 'A'){
                //Cortar Césped
                Matrix[p.x()][p.y()]='b';
                Visitados[p.x()][p.y()]=true;
                //Guardar como anterior
                viejo.setX(p.x());
                viejo.setY(p.y());
                pila.push_back(p);

                //Moverse
                p.ry()--;
                Matrix[p.x()][p.y()]='A';
                qDebug()<< "Arriba";
            }
        }
        Refrescar(donde,viejo);
    }
}

double MainWindow::manhattan(QPoint p1, QPoint p2)
{
    //FUNCIONA BIEN COMPROBADO
    return sqrt( pow((p2.x() - p1.x()),2)+pow((p2.y() - p1.y()),2));
}
