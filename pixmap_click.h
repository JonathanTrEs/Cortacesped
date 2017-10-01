#ifndef PIX_ITEM
#define PIX_ITEM

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsPixmapItem>
#include <QDebug>
#include "medio.h"
class pixmap_click : public QGraphicsPixmapItem
{

public:
    medio * canal;
    explicit pixmap_click();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif
