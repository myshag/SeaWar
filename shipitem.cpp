#include "shipitem.h"
#include <QPainter>

#include "QDebug"


ShipItem::ShipItem(Ship* ship)
{
  this->x = ship->start.x;
  this->y=ship->start.y;

  this->len = ship->lenght;
  this->direction = ship->direction;

  qDebug("Create ship: x= %d, y= %d, direction=%d,len=%d",x,y,direction,len);


}

void ShipItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

  float sizeBoard=painter->viewport().height();
  painter->scale(0.99,0.99);

  float sizeship=sizeBoard/10;
   painter->setBrush(QBrush(QColor(30,255,100,150), Qt::SolidPattern));
   QPen pen(Qt::black, 1);
   painter->setPen(pen);
   if (direction==Direction::Horizontal)
  painter->drawRoundedRect(-5.05*sizeship+(x+1)*sizeship,
                           -5.05*sizeship+(y+1)*sizeship,
                           sizeship*len,sizeship,5,5);
   else if (direction==Direction::Vertical)
     {
       painter->drawRoundedRect(-5.05*sizeship+(x+1)*sizeship,
                                -5.05*sizeship+(y+1)*sizeship
                                ,sizeship,sizeship*len,5,5);

     }
  painter->scale(1,1);

}

QRectF ShipItem::boundingRect() const
{
  return QRectF(sizeship*x,sizeship*y,sizeship,sizeship);
}
