#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include "Models/gamemodel.h"
#include "Controllers/BoardController.h"

enum class ShootResult {L,R,KILL};

class GameController : public QObject
{
  Q_OBJECT
public:
  explicit GameController(GameModel* model);
  void placeAIShips();
  void placeHumanShips();
  ShootResult humanShoot(int x,int y);

signals:

public slots:
  pressMouseOnBoard(int x, int y);

private:
  GameModel* _model;

  BoardController* aiBoardController;
  BoardController* humanBoardController;


};

#endif // GAMECONTROLLER_H
