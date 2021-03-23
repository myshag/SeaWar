#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initScene();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initScene()
{
    gameModel_1 =  new GameModel();
    gameModel_2 =  new GameModel();

    userScene1 = new BoardGameScene(gameModel_1);
    userScene2 = new BoardGameScene(gameModel_2);

    ui->gameBoardView_1->setScene(userScene1);
    ui->gameBoardView_2->setScene(userScene2);
}

