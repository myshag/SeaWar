#include "BoardModel.h"
#include "QRandomGenerator"
#include "QTime"
#include "QDebug"



const Cell BoardModel::getCell(int x, int y)
{
    if ((x<0)||(x>9)||(y<0)||(y>9))
    {
        return Cell{CellType::FREE,nullptr};
    }
    else
    {
        return board[x][y];
    }
}

void BoardModel::setCell(int x, int y, Cell cell)
{
    if ((x>=0)&&(x<=9)&&(y>=0)&&(y<=9))
    {
        board[x][y] = cell;
    }
    notifyUpdate();
}

void BoardModel::changeCellType(int x, int y, CellType newcelltype)
{
  if ((x>=0)&&(x<=9)&&(y>=0)&&(y<=9))
  {
       board[x][y].cellType =newcelltype;
  }


   notifyUpdate();

}

int BoardModel::leavShips()
{
  int res = 0;
  for (auto s:ships)
    {
      if (!s->isdead())
        {
        res++;
        }
    }
  return res;
}




BoardModel::BoardModel()
{


    for (int y=0;y<10;y++)
        for (int x=0;x<10;x++)
        {
            board[x][y].cellType = CellType::FREE;
        }

qDebug()<<"BoardModel.cpp: Create instance class BoardModel";

}

BoardModel::~BoardModel()
{
  for (int i=0;i<10;i++)
    {
      delete ships[i];
    }
  qDebug()<<"BoardModel.cpp: delete instance class BoardModel";
}





