#include "shipitem.h"
#include <QPainter>

#include "QDebug"
#include "exception"


ShipItem::ShipItem(const Ship *ship)
{

  if (ship==nullptr)
    {

      qFatal( "[Fatal Error] ShipItem::ShipItem(): ship is nullptr");
      throw std::exception();

    }

    x = ship->start().x;
    y=ship->start().y;

    len = ship->lenght();
    direction = ship->direction();

    qDebug("Created ship: x= %d, y= %d, direction=%d,len=%d",x,y,direction,len);





}

void ShipItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

  float sizeBoard=painter->viewport().height();
  painter->scale(0.99,0.99);

  float sizeship=sizeBoard/10;
   painter->setBrush(QBrush(QColor(30,255,100,100), Qt::SolidPattern));
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
