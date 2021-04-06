#include "gameview.h"
#include "QDebug"
#include <QMouseEvent>

GameView::GameView(QWidget *parent) :  QGraphicsView(parent)
{
    qDebug()<<"gameview.cpp: Create instance class GameView";

}

void GameView::mousePressEvent(QMouseEvent *event)
{
  QPointF coords = event->pos();
  int x  = (coords.x()/width())*10;
  int y  = (coords.y()/height())*10;
    emit pressMouseOnBoard(x,y);

}
