#ifndef BOARDGAMESCENE_H
#define BOARDGAMESCENE_H

#include <QGraphicsScene>
#include "Models/BoardModel.h"
#include "QRandomGenerator"

#include "QDebug"
#include "QGraphicsSceneMouseEvent"
#include "QGraphicsView"
#include "Observer/Observer.h"

class BoardGameScene : public QGraphicsScene, public Observer
{
    Q_OBJECT
public:
    BoardGameScene(BoardModel* model);

    void drawBackground(QPainter * painter, const QRectF & rect ) override;
    void updateObserver();

private:
    QColor lineColor = QColor(250,250, 250,255);
    QColor CellColor = QColor(0, 0, 200,200);

    QPen cellPen =  QPen(lineColor,1, Qt::DotLine);
    QBrush cellBrush = QBrush(CellColor, Qt::SolidPattern);

    BoardModel* _model;
    QRandomGenerator* gen;
};

#endif // BOARDGAMESCENE_H
