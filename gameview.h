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
  void mousePressEvent(QMouseEvent *event) override;


signals:
  void pressMouseOnBoard(int x,int y);


};

#endif // GAMEVIEW_H
