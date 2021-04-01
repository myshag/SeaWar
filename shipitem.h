#ifndef SHIPITEM_H
#define SHIPITEM_H

#include <QGraphicsItem>
#include "Models/BoardModel.h"


class ShipItem : public QGraphicsItem
{
public:
  ShipItem(const Ship *ship);
  virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
  virtual QRectF boundingRect() const;

private:

  int x;
  int y;

  int len;
  Direction direction;
  float sizeship;


};

#endif // SHIPITEM_H
