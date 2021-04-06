#include "gamecontroller.h"

GameController::GameController(GameModel *model)
{
  _model = model;
  aiBoardController = new BoardController(_model->BoardAI);
  humanBoardController =new  BoardController(_model->BoardHuman);
   qDebug()<<"gamecontroller.cpp: Create instance class GameController";
}

void GameController::placeAIShips()
{
  aiBoardController->placeShips();
  qDebug()<<"gamecontroller.cpp: placeAIShips()";

}

void GameController::placeHumanShips()
{

  humanBoardController->placeShips();
  qDebug()<<"gamecontroller.cpp: placeHumanShips()";

}

ShootResult GameController::humanShoot(int x, int y)
{

  qDebug()<<"gamecontroller.cpp: humanShoot()";

}

GameController::pressMouseOnBoard(int x, int y)
{
  CellType celltype = _model->BoardAI->getCell(x,y).cellType;
  Cell cell =_model->BoardAI->getCell(x,y);

  qDebug()<<x<<y;
  switch (celltype) {
    case CellType::AROUND:
    case CellType::FREE:
      _model->BoardAI->changeCellType(x,y,CellType::MISS);
      break;
     case CellType::SHIP:
      qDebug()<<"Shoot in ship"<<cell.ship->id();
       _model->BoardAI->changeCellType(x,y,CellType::DEMAGE);
       cell.ship->setDemage(1);



    default:
      break;
   }
}
