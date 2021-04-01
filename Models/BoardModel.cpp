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
}



BoardModel::BoardModel()
{



    for (int y=0;y<10;y++)
        for (int x=0;x<10;x++)
        {
            board[x][y].cellType = CellType::FREE;
        }



}

Cell BoardModel::operator[](int index)
{

}




