#include "gamecontroller.h"
#include "QMessageBox"
#include "vector"

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



void GameController::gameOver(bool humanWine)
{

  QMessageBox msgBox;
    msgBox.setText("The GameOver");
    msgBox.exec();

}

void GameController::findShipStep()
{
   humanBoardController->shoot(wreckedShip.x+1,wreckedShip.y);
   findShiploop=false;

}

void GameController::aiStep()
{

  if (!isgameOver) {
   std::vector<Point> findShipList;

  qDebug() << "AI Step";
  if (loopkill)
    {
      loopkillStep();
      return;
    }

  if (findShiploop)
    {
      findShipStep();
      return;
    }


  Point currShoot = genStep();

  lastAIShootResult = humanBoardController->shoot(currShoot);


  if (lastAIShootResult==ShootResult::WRECKED)
    {
      findShiploop = true;
      wreckedShip = currShoot;
      for (int i=0;i<4;i++)
        {

          //findShipList.insert();
        }

      aiStep();
    }

  if (lastAIShootResult==ShootResult::KILL)
    {
      humanBoardController->killShip(currShoot.x,currShoot.y);
      aliveHumanShips--;
      if(aliveHumanShips<=0)
        {
          isgameOver = true;
          gameOver(false);
        }
    };
  //qDebug() << "Human Step";
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
  if (!isgameOver)
    {
  ShootResult resShoot;
  resShoot =aiBoardController->shoot(x,y);

  if (resShoot==ShootResult::KILL)
    {
       aiBoardController->killShip(x,y);
       aliveAIShips--;
       if(aliveAIShips<=0)
         {
           isgameOver = true;
           gameOver(true);
         }
    };

  if (resShoot==ShootResult::MISS)
  {
    aiStep();
  }

}


}

void GameController::loopkillStep()
{

}
