#ifndef BOARDMODEL_H
#define BOARDMODEL_H

#include "Observer/Observer.h"
#include "models/ship.h"

enum class CellType
{
    FREE=0,
    SHIP,
    KILL,
    DEMAGE,
    MISS,
    AROUND

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
      notifyUpdate();
    }

    BoardModel();
    ~BoardModel();
    bool placeShip(Ship* ship);

    void changeCellType(int x, int y, CellType newcelltype);
private:
    Ship* ships[10];
    bool placeHShip(Ship* ship);
    bool placeVShip(Ship* ship);
    bool placeShips();

    Cell board[10][10];

};

#endif // BOARDMODEL_H
