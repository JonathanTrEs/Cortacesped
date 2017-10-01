#include "pixmap_click.h"

pixmap_click::pixmap_click()
{
    //Crea la forma de comunicar las coordenadas de los clicks del raton
    //por un objeto de la clase object
    //mediante el uso de señales
    canal = new medio();
}

//Cuando se hace click, automaticamente se llama a la señal de canal
//Llamo a una funcion de la clase medio
//Le paso el objeto canal como puntero indefinido
void pixmap_click::mousePressEvent(QGraphicsSceneMouseEvent *mouse){

    //Esto es una especie de emit artesanal porque pixmap_click
    //No hereda de QObject directamente y no se puede usar el emit como tal
    //Se le pasa el propio objeto pixmap_click
    if(mouse->button() == Qt::LeftButton)
        canal->medioEmit(dynamic_cast<void *>(this),0);
    else if(mouse->button() == Qt::RightButton)
        canal->medioEmit(dynamic_cast<void *>(this),1);




}



