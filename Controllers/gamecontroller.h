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
  void gameOver(bool humanWine);
  void aiStep();
  Point genStep();




signals:

public slots:
  pressMouseOnBoard(int x, int y);

private:
  bool isgameOver = false;
  int aliveAIShips = 10;
  int aliveHumanShips = 10;
  GameModel* _model;
  int humanShips=10;
  int aiShips=10;
  bool loopkill=false;
  bool findShiploop=false;
  void findShipStep();

  Point wreckedShip;




  int loopKillCount;
  void loopkillStep();
  ShootResult lastAIShootResult;
  ShootResult lastHumanShootResult;
  Point lastAIShootPoint;

  BoardController* aiBoardController;
  BoardController* humanBoardController;
  QRandomGenerator* gen=QRandomGenerator::global();



};

#endif // GAMECONTROLLER_H
