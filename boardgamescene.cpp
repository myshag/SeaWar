#include "boardgamescene.h"
#include <QPainter>
#include <QGraphicsItem>
#include "shipitem.h"


BoardGameScene::BoardGameScene(BoardModel* model,bool showShips)
{

  _model=model;
  _model->addObserver(this);
  this->showShips = showShips;

  if (showShips)
    {
   for (int i=0; i<10;i++)
     {
      addItem(new ShipItem(_model->getShip(i)));
     }
    }

     qDebug()<<"shipitem.cpp: Create instance class BoardGameScene";

}




void BoardGameScene::drawBackground(QPainter *painter, const QRectF &rect)
{
   setSceneRect(0,0,100,100);
   painter->setRenderHint(
      QPainter::Antialiasing);
     painter->setPen(cellPen);
     painter->setBrush(cellBrush);

     int stepY = rect.height()/10;
     int stepX = rect.width()/10;
     int sx = rect.left();
     int sy = rect.top();

     for (int y=0;y<10;y++)
       for (int x=0;x<10;x++)
         {
           if (_model->getCell(x,y).cellType == CellType::FREE)
             {
               painter->setPen(cellPen);
               painter->setBrush(cellBrush);

                 painter->drawRect(sx+stepX*x,
                            sy+stepY*y,
                            stepX,stepY);
             } else if (_model->getCell(x,y).cellType == CellType::DEMAGE)
             {

               painter->setPen(QPen(QColor(150, 40, 100,255),1, Qt::DotLine));
               painter->setBrush(QBrush(QColor(150, 40, 100,255), Qt::SolidPattern));

             painter->drawRect(sx+stepX*x,
                               sy+stepY*y,
                               stepX,stepY);


             }
           else if (_model->getCell(x,y).cellType == CellType::MISS)
             {


               painter->setPen(QPen(QColor(100, 0, 0,150),1, Qt::DotLine));
               painter->setBrush(QBrush(QColor(200, 0, 0,150), Qt::SolidPattern));

               painter->drawEllipse(sx+stepX*x+stepX/2-5,
                                 sy+stepY*y+stepY/2-5,10,10);
               painter->setPen(cellPen);
               painter->setBrush(cellBrush);
               painter->drawRect(sx+stepX*x,
                                 sy+stepY*y,
                                 stepX, stepX);


             } else if (_model->getCell(x,y).cellType == CellType::AROUND)
             {

               painter->setPen(cellPen);
               painter->setBrush(cellBrush);

               painter->drawRect(sx+stepX*x,
                                 sy+stepY*y,
                                 stepX, stepX);



             }
           else if (_model->getCell(x,y).cellType == CellType::SHIP)
                        {
               int id=0;
               if (_model->getCell(x,y).ship!=nullptr)
                 {
                   id = _model->getCell(x,y).ship->id();
                 }

               painter->setPen(cellPen);
               painter->setBrush(cellBrush);

               painter->drawRect(sx+stepX*x,
                                 sy+stepY*y,
                                 stepX, stepX);

             }
         }







}

void BoardGameScene::updateObserver()
{
  qDebug() <<"BoardGameScene::update()";
  //this->views().first()->update();
  this->invalidate();
  //update(0,0,width(),height());

 // for (auto s:this->items())
 //   {
 //     (Ship*)s->update();
 //   }

}


