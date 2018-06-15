#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("2048小游戏-樊克虎-2016060102020");
    w.setWindowFlags(Qt::WindowCloseButtonHint);
    w.show();

    return a.exec();
}
