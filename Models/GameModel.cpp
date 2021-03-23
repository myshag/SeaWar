#include "GameModel.h"
#include "QRandomGenerator"
#include "QTime"



Cell GameModel::getCell(int x, int y)
{
  if ((x<0)||(x>9)||(y<0)||(y>9))
    {
      return Cell{CellType::FREE,-1};
    }
  else
    {
      return board[x][y];
    }
}

void GameModel::setCell(int x, int y, Cell cell)
{
  if ((x>=0)&&(x<=9)&&(y>=0)&&(y<=9))
    {
      board[x][y] = cell;
    }
}


GameModel::GameModel()
{
   QTime time;

   QRandomGenerator* gen = QRandomGenerator::global();



  for (int y=0;y<10;y++)
    for (int x=0;x<10;x++)
      {
        board[x][y].cellType = CellType::FREE;
      }

  int indexShip=0;



  int len_ship[10] = {1,1,1,1,2,2,2,3,3,4};
  while (indexShip<10)
    {
      int x = gen->bounded(0,9);
      int y = gen->bounded(0,9);
      Direction dir = static_cast<Direction>(gen->bounded(0,3));
      if (placeShip(x,y,dir,len_ship[indexShip]))
      {
        indexShip++;
      }
      else
      {
        continue;
      }



    }

  board[1][3].cellType = CellType::DEMAGE;
  board[1][5].cellType = CellType::MISS;
}



bool GameModel::placeHShip(int x, int y, int len)
{
  if ((y+len)>9) {
      return false;
    } else
    {
      int summ = 0;
      for (int j = y-1;j <= y+1; j++)
        for (int i = x-1;i <= x+len+1; i++)
          {
            summ+=static_cast<int>(getCell(i,j).cellType);
          }
      if (summ==0)
        {
          for (int i=0;i<len;i++)
            {
              Cell cell;
              cell.cellType=CellType::SHIP;
               setCell(x+i,y,cell);
            }
        }
    }

}

bool GameModel::placeVShip(int x, int y, int len)
{

}


bool GameModel::placeShip(int x, int y, Direction dir, int len)
{

      switch (dir) {
      case Direction::Horizontal:
          return placeHShip(x, y, len);
      break;

      case Direction::Vertical:
          return placeVShip(x, y, len);

      break;
     }

}



