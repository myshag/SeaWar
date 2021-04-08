#include "BoardController.h"

BoardController::BoardController(BoardModel* model)
{
  _model = model;
  qDebug()<<"BoardController.cpp: Create instance class BoardController";

}

void BoardController::CursorSceneCoordsX(int coordX)
{

}

void BoardController::CursorSceneCoordsY(int coordY)
{

}


bool BoardController::placeShips()
{
  qDebug()<<"BoardController.cpp: BoardController::placeShips()";

  int indexShip=0;
  int len_ship[10] = {4,3,3,2,2,2,1,1,1,1};
  long long N = 0;
  while (indexShip<10)
    {
      Point start, end;
      Direction direction = (Direction)gen->bounded(0,2);
      int lenght = len_ship[indexShip];

      int x = gen->bounded(0,10);
      int y = gen->bounded(0,10);

      start = {x,y};

      if ( direction==Direction::Horizontal)
        {
          end = {x+lenght-1,y};
        }  else if ( direction==Direction::Vertical)
        {
          end = {x,y+lenght-1};
        }


      Ship* ship = new Ship(indexShip,
                            start,
                            end,
                            lenght,
                            direction);




      if (placeShip(ship))
        {
          _model->setShip(ship,indexShip);
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

void BoardController::killShip(Ship *ship)
{
  int startX = ship->start().x-1;
  int endX = ship->end().x+1;

  int startY = ship->start().y-1;
  int endY = ship->end().y+1;

  for (int y = startY;y <= endY; y++)
    for (int x = startX;x <= endX; x++)
      {
        if (_model->getCell(x,y).cellType!=CellType::SHIP)
          _model->changeCellType(x,y,CellType::MISS);

      }

  if ( ship->direction()==Direction::Vertical)
    {
      for (int i=0;i<ship->lenght();i++)
        {
          _model->changeCellType(
                ship->start().x,ship->start().y+i,CellType::DEMAGE);
        }
    }

  if ( ship->direction()==Direction::Horizontal)
    {
      for (int i=0;i<ship->lenght();i++)
        {
          _model->changeCellType(
                ship->start().x+i,ship->start().y,CellType::DEMAGE);
        }
    }

}

ShootResult BoardController::shoot(Point point)
{
  return  shoot(point.x,point.y);
}
ShootResult BoardController::shoot(int x, int y)
{
  CellType celltype = _model->getCell(x,y).cellType;
  Cell cell =_model->getCell(x,y);

  qDebug()<<"Shoot to: "<<x<<" : "<<y;
  switch (celltype) {
    case CellType::AROUND:
    case CellType::FREE:
      _model->changeCellType(x,y,CellType::MISS);
       return ShootResult::MISS;

      break;

    case CellType::SHIP:
      qDebug()<<"Shoot in ship"<<cell.ship->id();
      _model->changeCellType(x,y,CellType::DEMAGE);
      cell.ship->setDemage();
      if (cell.ship->isdead())
        {
          return ShootResult::KILL;
        }
      else
        {
          return ShootResult::WRECKED;
        }

     break;

    default:
            return ShootResult::MISS;
            break;
        }


    }



  bool BoardController::placeHShip(Ship* ship)
  {
    if (ship->end().x>9) {
        return false;
      }

    int startX = ship->start().x-1;
    int endX = ship->end().x+1;

    int startY = ship->start().y-1;
    int endY = ship->end().y+1;


    for (int y = startY;y <= endY; y++)
      for (int x = startX;x <= endX; x++)
        {
          if (_model->getCell(x,y).cellType==CellType::SHIP)
            {
              return false;
            };
        }


    for (int y = startY;y <= endY; y++)
      for (int x = startX;x <= endX; x++)
        {
          if (_model->getCell(x,y).cellType==CellType::FREE)
            {
              _model->setCell(x,y,Cell{CellType::AROUND,ship});
            }
        }

    for (int i=0;i<ship->lenght();i++)
      {
        _model->setCell(ship->start().x+i,
                        ship->start().y,
                        Cell{CellType::SHIP,ship});
      }

    return true;


  }

  bool BoardController::placeVShip(Ship* ship)
  {
    if ((ship->end().y)>9) {
        return false;
      } else
      {


        int startX = ship->start().x-1;
        int endX = ship->end().x+1;

        int startY = ship->start().y-1;
        int endY = ship->end().y+1;


        for (int y = startY;y <= endY; y++)
          for (int x = startX;x <= endX; x++)
            {
              if (_model->getCell(x,y).cellType==CellType::SHIP)
                {
                  return false;
                };
            }


        for (int y = startY;y <= endY; y++)
          for (int x = startX;x <= endX; x++)
            {
              if (_model->getCell(x,y).cellType==CellType::FREE)
                {
                  _model->setCell(x,y,Cell{CellType::AROUND,ship});
                }
            }

        for (int i=0;i<ship->lenght();i++)
          {
            Cell cell;
            cell.ship=ship;
            cell.cellType=CellType::SHIP;
            _model->setCell(ship->start().x,ship->start().y+i,cell);
          }
        return true;


      }

  }


  bool BoardController::placeShip(Ship* ship)
  {

    bool res =false;

    switch (ship->direction()) {
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
               ship->start().x+1,
               ship->start().y+1,
               ship->lenght(),
               ship->direction(),
               ship->id());
        return true;


      }
    else

      return res;

  }
