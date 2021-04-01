#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "shipitem.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initGame();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGame()
{
    gameModel_1 =  new BoardModel();
    gameModel_2 =  new BoardModel();

    boardController1 = new GameController(gameModel_1);
    boardController1->placeShips();

    boardController2 = new GameController(gameModel_2);
    boardController2->placeShips();





    userScene1 = new BoardGameScene(gameModel_1);
    userScene2 = new BoardGameScene(gameModel_2);

    userScene1->setSceneRect(0,0,100,100);
    userScene2->setSceneRect(0,0,100,100);



/*


    for (int i=0;i<10;i++)
      {
      ShipItem *item = new ShipItem(gameModel_2->ships[i]);
      userScene2->addItem(item);
      }

*/



    ui->gameBoardView_1->setScene(userScene1);
    ui->gameBoardView_2->setScene(userScene2);
}

