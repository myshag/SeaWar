#include "boardgamescene.h"
#include <QPainter>
#include <QGraphicsItem>
#include "shipitem.h"


BoardGameScene::BoardGameScene(BoardModel* model)
{
  _model=model;

   for (int i=0; i<10;i++)
     {
      addItem(new ShipItem(_model->getShip(i)));
     }

}




void BoardGameScene::drawBackground(QPainter *painter, const QRectF &rect)
{
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

              painter->setPen(QPen(QColor(250,250, 250,255),1, Qt::DotLine));
              painter->setBrush(QBrush(QColor(0, 0, 200,100), Qt::SolidPattern));

             painter->drawRect(sx+stepX*x,
                               sy+stepY*y,
                               stepX,stepY);

             painter->setPen(QPen(QColor(100, 0, 0,150),1, Qt::DotLine));
             painter->setBrush(QBrush(QColor(200, 0, 0,150), Qt::SolidPattern));

             painter->drawEllipse(sx+stepX*x+stepX/2-5,
                               sy+stepY*y+stepY/2-5,10,10);
             }
           else if (_model->getCell(x,y).cellType == CellType::MISS)
             {
               painter->setPen(QPen(QColor(250,250, 250,255),1, Qt::DotLine));
               painter->setBrush(QBrush(QColor(0, 0, 200,100), Qt::SolidPattern));

               painter->drawRect(sx+stepX*x,
                                 sy+stepY*y,
                                 stepX, stepX);
               painter->drawLine( sx+stepX*x,
                                  sy+stepY*y,
                                  sx+stepX*x+stepX,
                                  sy+stepY*y+stepY);

               painter->drawLine( sx+stepX*x+stepX,
                                  sy+stepY*y,
                                  sx+stepX*x,
                                  sy+stepY*y+stepY);

             } else if (_model->getCell(x,y).cellType == CellType::AROUND)
             {

               painter->setPen(QPen(QColor(250,250, 250,255),1, Qt::DotLine));
               painter->setBrush(QBrush(QColor(0, 0, 200,100), Qt::SolidPattern));




               painter->drawRect(sx+stepX*x,
                                 sy+stepY*y,
                                 stepX, stepX);

               /* painter->setPen(QPen(QColor(25,250, 250,255),1, Qt::SolidLine));
               painter->drawText(start_x+step_x*x+step_x/2-5,
                                 start_y+step_y*y+step_y/2-5,QString::number(id));
              */

             }
           else if (_model->getCell(x,y).cellType == CellType::SHIP)
                        {
               int id=0;
               if (_model->getCell(x,y).ship!=nullptr)
                 {
                   id = _model->getCell(x,y).ship->id;
                 }

               painter->setPen(QPen(QColor(250,250, 250,255),1, Qt::DotLine));
               painter->setBrush(QBrush(QColor(0, 0, 200,100), Qt::SolidPattern));

               painter->drawRect(sx+stepX*x,
                                 sy+stepY*y,
                                 stepX, stepX);
              /* painter->setPen(QPen(QColor(25,250, 250,255),1, Qt::SolidLine));
               painter->drawText(start_x+step_x*x+step_x/2-5,
                                 start_y+step_y*y+step_y/2-5,QString::number(id));*/


             }
         }







}

void BoardGameScene::update()
{
  this->update();
 // for (auto s:this->items())
 //   {
 //     (Ship*)s->update();
 //   }

}


