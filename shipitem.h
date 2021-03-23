#ifndef SHIPITEM_H
#define SHIPITEM_H

#include <QGraphicsItem>


class ShipItem : public QGraphicsItem
{
public:
  ShipItem();
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // SHIPITEM_H
