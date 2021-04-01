#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include "Observer/Observer.h"

enum class CellType
{
    FREE=0,
    SHIP,
    KILL,
    DEMAGE,
    MISS,
    AROUND

};

struct Point
{
    int x;
    int y;

};

enum class Direction
{

   Horizontal,
  Vertical

};


struct Ship {
    Point start;
    Point end;
    int lenght;
    bool isdead;
    Direction direction;
    int id;


};


struct Cell{
    CellType cellType;
    Ship* ship;
};




class BoardModel : public Observable
{


public:


    const Cell getCell(int x, int y);

    void setCell(int x, int y, Cell cell);

    const Ship* getShip(int index)
    {
      if ((index>=0)&&(index<=9))
        {
          return ships[index];
        }
      else
        {
          return nullptr;
        }

    }
    void setShip(Ship* ship,int index)
    {
      if ((index>=0)&&(index<=9))
        {
          ships[index] = ship;
        }
    }

    BoardModel();
    bool placeShip(Ship* ship);

private:
    Ship* ships[10];
    bool placeHShip(Ship* ship);
    bool placeVShip(Ship* ship);
    bool placeShips();

    Cell board[10][10];
    Cell operator[](int index);
};

#endif // GAMEMODEL_H
