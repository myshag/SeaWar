#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsSceneMouseEvent>

class GameView : public QGraphicsView
{
  Q_OBJECT
public:
  GameView(QWidget *parent=0);
  void mousePressEvent(QGraphicsSceneMouseEvent *event);


signals:
  void CursorSceneCoordsX(int coordX);
  void CursorSceneCoordsY(int coordY);

};

#endif // GAMEVIEW_H
