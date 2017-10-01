#include "medio.h"

//Llama a la funcion de la clase medio
//Cuando se llame a mousePressed de la clase medio
//Existe un conect que detecta el cambio
//Pasandole el QGraphicsSceneMouseEvent por argumento
void medio::medioEmit(void * e,bool b)
{
    emit mousePressed(e,b);

}

