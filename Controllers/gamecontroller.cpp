#include "gamecontroller.h"
#include "QMessageBox"

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



void GameController::gameOver()
{

  QMessageBox msgBox;
    msgBox.setText("The GameOver");
    msgBox.exec();

}

void GameController::aiStep(bool loopkill=false)
{
  //CellType celltype;
  static int x;
  static int y;

  static CellType celltype;
  static ShootResult resShoot;

  if (!loopkill)
    {
      ShootResult= humanBoardController->shoot(genStep());
    }


  if (resShoot==ShootResult::WRECKED)
    {
      killloop=true;

      humanBoardController->shoot(x+1,y);
    }




}

Point GameController::genStep()
{
  int x,y;
  CellType celltype;
  do {
      x = gen->bounded(0,10);
      y = gen->bounded(0,10);
      celltype = _model->BoardHuman->getCell(x,y).cellType;
      qDebug()<<x<<y<<"celltype"<<(int)celltype;
    } while ((celltype==CellType::DEMAGE)||
             (celltype==CellType::MISS)||
             (celltype==CellType::KILL));

  return Point{x,y};


}




GameController::pressMouseOnBoard(int x, int y)
{
  aiBoardController->shoot(x,y);
  aiStep();

}
