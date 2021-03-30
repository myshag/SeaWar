#include "GameModel.h"
#include "QRandomGenerator"
#include "QTime"
#include "QDebug"



Cell GameModel::getCell(int x, int y)
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

void GameModel::setCell(int x, int y, Cell cell)
{
    if ((x>=0)&&(x<=9)&&(y>=0)&&(y<=9))
    {
        board[x][y] = cell;
    }
}

bool GameModel::placeShips()
{
    QRandomGenerator* gen = QRandomGenerator::global();
    int indexShip=0;
    int len_ship[10] = {4,3,3,2,2,2,1,1,1,1};
    long long N = 0;
    while (indexShip<10)
    {
        int x = gen->bounded(0,10);
        int y = gen->bounded(0,10);
        //int x = 9;
        //int y =1;

        Ship* ship = new Ship();
        ship->start = {x,y};
        ship->lenght = len_ship[indexShip];
        ship->isdead = false;
        ship->direction  = (Direction)gen->bounded(0,2);
        ship->id = indexShip;

        if ( ship->direction==Direction::Horizontal)
        {
            ship->end = {x+ship->lenght-1,y};
        }  else if ( ship->direction==Direction::Vertical)
        {
            ship->end = {x,y+ship->lenght-1};
        }

        if (placeShip(ship))
        {
            ships[indexShip]=ship;
            indexShip++;
        }
        else
        {
            delete ship;
        }
        N++;
        if (N>1000000)
        {
            qDebug() <<"I am not palce ships, exit...";
            break;
            return false;
        }

    }
    return true;
}

GameModel::GameModel()
{



    for (int y=0;y<10;y++)
        for (int x=0;x<10;x++)
        {
            board[x][y].cellType = CellType::FREE;
        }

    if (!placeShips())
    {
        placeShips();
    }


}



bool GameModel::placeHShip(Ship* ship)
{
    if (ship->end.x>9) {
        return false;
    }

    int startX = ship->start.x-1;
    int endX = ship->end.x+1;

    int startY = ship->start.y-1;
    int endY = ship->end.y+1;


    for (int y = startY;y <= endY; y++)
        for (int x = startX;x <= endX; x++)
        {
            if (getCell(x,y).cellType==CellType::SHIP)
            {
                return false;
            };
        }


    for (int y = startY;y <= endY; y++)
        for (int x = startX;x <= endX; x++)
        {
            if (getCell(x,y).cellType==CellType::FREE)
            {
            setCell(x,y,Cell{CellType::AROUND,ship});
            }
        }

    for (int i=0;i<ship->lenght;i++)
    {
        setCell(ship->start.x+i,
                ship->start.y,
                Cell{CellType::SHIP,ship});
    }

    return true;


}

bool GameModel::placeVShip(Ship* ship)
{
    if ((ship->end.y)>9) {
        return false;
    } else
    {


        int startX = ship->start.x-1;
        int endX = ship->end.x+1;

        int startY = ship->start.y-1;
        int endY = ship->end.y+1;


        for (int y = startY;y <= endY; y++)
            for (int x = startX;x <= endX; x++)
            {
                if (getCell(x,y).cellType==CellType::SHIP)
               {
                    return false;
                };
            }


        for (int y = startY;y <= endY; y++)
            for (int x = startX;x <= endX; x++)
            {
                if (getCell(x,y).cellType==CellType::FREE)
                {
                setCell(x,y,Cell{CellType::AROUND,ship});
                }
            }

        for (int i=0;i<ship->lenght;i++)
        {
            Cell cell;
            cell.ship=ship;
            cell.cellType=CellType::SHIP;
            setCell(ship->start.x,ship->start.y+i,cell);
        }
        return true;


    }

}


bool GameModel::placeShip(Ship* ship)
{

    bool res =false;

    switch (ship->direction) {
    case Direction::Horizontal:
        res = placeHShip(ship);
        break;

    case Direction::Vertical:
        res = placeVShip(ship);

        break;
    default:
        res = false;
        break;
        return res;

    }

    if (res)
    {
        qDebug("Place ship to (%d, %d) len=%d, Direction=%d (Horiz=0), id=%d",
               ship->start.x+1,
               ship->start.y+1,
               ship->lenght,
               ship->direction,
               ship->id);
        return true;


    }
    else

        return res;

}



