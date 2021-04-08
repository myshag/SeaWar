#ifndef BOARDCONTROLLER_H
#define BOARDCONTROLLER_H


#include "QObject"
#include "Models/BoardModel.h"
#include  "QRandomGenerator"
#include "qDebug"


enum class ShootResult {MISS,WRECKED,KILL};

class BoardController: public QObject
{

  Q_OBJECT

  public:
  BoardController(BoardModel* model );





private slots:

  bool placeVShip(Ship *ship);
  bool placeHShip(Ship *ship);


public slots:

  bool placeShip(Ship *ship);
  bool placeShips();
  void killShip(Ship* ship);
  ShootResult shoot(int x, int y);
  ShootResult shoot(Point point);

  void CursorSceneCoordsX(int coordX);
  void CursorSceneCoordsY(int coordY);




private:
  BoardModel*_model;
   QRandomGenerator* gen=QRandomGenerator::global();




};

#endif
