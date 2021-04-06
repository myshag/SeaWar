#ifndef BOARDCONTROLLER_H
#define BOARDCONTROLLER_H


#include "QObject"
#include "Models/BoardModel.h"
#include  "QRandomGenerator"
#include "qDebug"


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

  void CursorSceneCoordsX(int coordX);
  void CursorSceneCoordsY(int coordY);




private:
  BoardModel*_model;
   QRandomGenerator* gen=QRandomGenerator::global();




};

#endif
