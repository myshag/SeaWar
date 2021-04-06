#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "boardgamescene.h"
#include "Models/BoardModel.h"
#include "Models/GameModel.h"
#include "Controllers/BoardController.h"
#include "Controllers/GameController.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    void initGame();
    GameModel* gameModel;
    GameController* controller;


    Ui::MainWindow *ui;
    GameModel* boardModel;
    BoardGameScene *AIBoardScene;
    BoardGameScene *HumanBoardScene;





};
#endif // MAINWINDOW_H
