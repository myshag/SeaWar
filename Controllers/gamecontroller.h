#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include "Models/gamemodel.h"
#include "Controllers/BoardController.h"
#include  "QRandomGenerator"


class GameController : public QObject
{
  Q_OBJECT
public:
  explicit GameController(GameModel* model);
  void placeAIShips();
  void placeHumanShips();
  void gameOver();
  void aiStep(bool killloop=false);
  Point genStep();



signals:

public slots:
  pressMouseOnBoard(int x, int y);

private:
  GameModel* _model;
  int humanShips=10;
  int aiShips=10;

  BoardController* aiBoardController;
  BoardController* humanBoardController;
  QRandomGenerator* gen=QRandomGenerator::global();



};

#endif // GAMECONTROLLER_H
