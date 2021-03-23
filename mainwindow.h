#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "boardgamescene.h"
#include "Models/GameModel.h"

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
    void initScene();
    GameModel* gameModel_1;
    GameModel* gameModel_2;

    Ui::MainWindow *ui;
    BoardGameScene *userScene1;
    BoardGameScene *userScene2;


};
#endif // MAINWINDOW_H
