#include "gameview.h"

GameView::GameView(QWidget *parent) :  QGraphicsView(parent)
{

}

void GameView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  QPointF coords = event->scenePos();
    emit CursorSceneCoordsX((int)coords.x());
    emit CursorSceneCoordsY((int)coords.y());
  // QGraphicsScene::mouseMoveEvent(event);
}
