#ifndef MEDIO_H
#define MEDIO_H

#include <QDebug>
#include <QObject>


class medio: public QObject
{
Q_OBJECT
public:
    medio(){};
    void medioEmit(void *,bool);

signals:
    void mousePressed(void *,bool); //Señal de click
};

#endif // MEDIO_H
