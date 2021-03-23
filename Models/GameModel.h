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

struct Cell{
    CellType cellType;
    int ship;
};

enum class Direction
{

   Horizontal,
  Vertical

};

struct Point
{
    int x;
    int y;

};

struct Ship {
    Point start;
    Point end;
    int lenght;
    bool isdead;
    Direction direction;


};

class GameModel
{


public:

    Ship ships[10];
    Cell getCell(int x, int y);
    void setCell(int x, int y, Cell cell);

    GameModel();
    bool placeShip(int x, int y, Direction dir, int len);
private:
    bool placeHShip(int x, int y, int len);
    bool placeVShip(int x, int y, int len);

    Cell board[10][10];
};

#endif // GAMEMODEL_H
