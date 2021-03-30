#ifndef GAMEMODEL_H
#define GAMEMODEL_H


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




class GameModel
{


public:

    Ship* ships[10];
    Cell getCell(int x, int y);
    void setCell(int x, int y, Cell cell);

    GameModel();
    bool placeShip(Ship* ship);
private:
    bool placeHShip(Ship* ship);
    bool placeVShip(Ship* ship);
    bool placeShips();

    Cell board[10][10];
};

#endif // GAMEMODEL_H
