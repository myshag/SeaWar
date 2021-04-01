#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "boardgamescene.h"
#include "Models/BoardModel.h"
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
    BoardModel* gameModel_1;
    BoardModel* gameModel_2;
    GameController*  boardController1;
    GameController* boardController2;

    Ui::MainWindow *ui;
    BoardGameScene *userScene1;
    BoardGameScene *userScene2;





};
#endif // MAINWINDOW_H
