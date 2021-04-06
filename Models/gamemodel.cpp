#include "gamemodel.h"
#include "QDebug"

GameModel::GameModel()
{
  qDebug()<<"gamemodel.cpp: Create instance class GameModel";

  BoardHuman = new BoardModel();
  BoardAI = new BoardModel();

}

GameModel::~GameModel()
{
  qDebug()<<"gamemodel.cpp: delete instance class GameModel";
  delete BoardHuman;
  delete BoardAI;

}
