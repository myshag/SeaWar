#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "Boardmodel.h"


class GameModel
{
public:
  GameModel();

private:
  BoardModel* BoardHuman;

  BoardModel* BoardAI;


};

#endif // GAMEMODEL_H
