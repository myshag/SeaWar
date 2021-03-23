#include "shipitem.h"
#include <QPainter>

ShipItem::ShipItem()
{

}

void ShipItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->drawPoint(7,7);
}
