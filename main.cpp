#include "mainwindow.h"
#include "QDebug"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qDebug()<<"main.cpp: show MainWindow...";
    w.show();
    return a.exec();
}
