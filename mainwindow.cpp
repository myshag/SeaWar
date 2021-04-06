#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "shipitem.h"
#include "QDebug"
#include "QLabel"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    gameModel  = new GameModel();
    controller = new GameController(gameModel);

    controller->placeAIShips();
    controller->placeHumanShips();


    AIBoardScene = new BoardGameScene(gameModel->BoardAI);
    HumanBoardScene = new BoardGameScene(gameModel->BoardHuman);

    ui->aiBoardView->setScene(AIBoardScene);
    ui->humanBoardView->setScene(HumanBoardScene);
    ui->statusbar->addWidget(new QLabel("---"));
    QObject::connect(ui->aiBoardView,SIGNAL(pressMouseOnBoard(int,int)),
                     controller,SLOT(pressMouseOnBoard(int,int)));


    //initGame();
}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initGame()
{
   /* gameModel_1 =  new BoardModel();
    gameModel_2 =  new BoardModel();

    boardController1 = new BoardController(gameModel_1);
    boardController1->placeShips();

    boardController2 = new BoardController(gameModel_2);
    boardController2->placeShips();

    userScene1 = new BoardGameScene(gameModel_1);
    userScene2 = new BoardGameScene(gameModel_2);*/







}

