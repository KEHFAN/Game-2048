#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <string.h>
int * map[4];
typedef int TYPE;
const unsigned char LEFT = 0X4B;
const unsigned char RIGHT = 0X4D;
const unsigned char DOWN = 0X50;
const unsigned char UP = 0X48;
const unsigned char RESTART=97;//重新开始
const unsigned char EXIT=100;//退出游戏
void InitGame(TYPE ** map, int L);
void RInitGame(TYPE ** map, int L);
void RandNum(TYPE ** map, int L);
void Output(TYPE ** map, int L);
void toLEFT(TYPE ** map);
void toRIGHT(TYPE ** map);
void toDOWN(TYPE ** map);
void toUP(TYPE ** map);
/*	初始化游戏数组
4*4二维数组
外部声明指针数组
例如：TYPE * map[H]
参数L为数组宽度 4*4
*/
void InitGame(TYPE ** map, int L) {
    int x = -1;
    int y = -1;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < L; i++) {
        map[i] = (TYPE*)malloc(L * sizeof(TYPE));
    }
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            map[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        do {
            x = rand() % 4;
            y = rand() % 4;
        } while (map[x][y] != 0);
        map[x][y] = 2;
    }
}
/***************************
重置map（重新开始）
****************************/
void RInitGame(TYPE ** map, int L) {
    int x = -1;
    int y = -1;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            map[i][j] = 0;
        }
    }
    for (int i = 0; i < 2; i++) {
        do {
            x = rand() % 4;
            y = rand() % 4;
        } while (map[x][y] != 0);
        map[x][y] = 2;
    }
}
/***************************
生成新数字块（2）
位置随机（在无数字块的区域0表示）
开局生成两个2数字块
****************************/
void RandNum(TYPE ** map, int L) {
    int x = -1;
    int y = -1;
    srand((unsigned int)time(NULL));

    //非开局 生成一个数字块
    do {
        x = rand() % 4;
        y = rand() % 4;
    } while (map[x][y] != 0);
    map[x][y] = 2;

}
/***************************
    输出演示
****************************/
void Output(TYPE ** map, int L) {
    printf("\n---------------------------\n\n\n");
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < L; j++) {
            printf("%d\t",map[i][j]);
        }
        printf("\n\n\n");
    }
    printf("---------------------------\n");
}
/***************************
    LEFT
****************************/
void toLEFT(TYPE ** map) {
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < 4; i++) {//遍历每一行
        a = map[i][0];
        b = map[i][1];
        c = map[i][2];
        d = map[i][3];

        if (b == 0 && c == 0 && a == d) {
            a = a + d;
            d = 0;
        }
        else if (a == b) {
            a = a + b;
            b = 0;
            if (c == d) {
                c = c + d;
                d = 0;
            }
        }
        else if (b == 0 && a == c) {
            a = a + c;
            c = 0;
        }
        else if (c == 0 && b == d) {
            b = b + d;
            d = 0;
        }
        else if (b == c) {
            b = b + c;
            c = 0;
        }
        else if (c == d) {
            c = c + d;
            d = 0;
        }


        //循环将0后移
        int temp = 0;
        for (int k = 0; k < 3; k++) {
            if (a == 0) {
                temp = a;
                a = b;
                b = temp;
            }
            if (b == 0) {
                temp = b;
                b = c;
                c = temp;
            }
            if (c == 0) {
                temp = c;
                c = d;
                d = temp;
            }
        }
        //更新map
        map[i][0] = a;
        map[i][1] = b;
        map[i][2] = c;
        map[i][3] = d;
    }
}
/***************************
    RIGHT
****************************/
void toRIGHT(TYPE ** map) {
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < 4; i++) {//遍历每一行
        d = map[i][0];
        c = map[i][1];
        b = map[i][2];
        a = map[i][3];

        if (b == 0 && c == 0 && a == d) {
            a = a + d;
            d = 0;
        }
        else if (a == b) {
            a = a + b;
            b = 0;
            if (c == d) {
                c = c + d;
                d = 0;
            }
        }
        else if (b == 0 && a == c) {
            a = a + c;
            c = 0;
        }
        else if (c == 0 && b == d) {
            b = b + d;
            d = 0;
        }
        else if (b == c) {
            b = b + c;
            c = 0;
        }
        else if (c == d) {
            c = c + d;
            d = 0;
        }


        //循环将0后移
        int temp = 0;
        for (int k = 0; k < 3; k++) {
            if (a == 0) {
                temp = a;
                a = b;
                b = temp;
            }
            if (b == 0) {
                temp = b;
                b = c;
                c = temp;
            }
            if (c == 0) {
                temp = c;
                c = d;
                d = temp;
            }
        }
        //更新map
        map[i][0] = d;
        map[i][1] = c;
        map[i][2] = b;
        map[i][3] = a;
    }
}
/***************************
    DOWN
****************************/
void toDOWN(TYPE ** map) {
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < 4; i++) {//遍历每一行
        d = map[0][i];
        c = map[1][i];
        b = map[2][i];
        a = map[3][i];

        if (b == 0 && c == 0 && a == d) {
            a = a + d;
            d = 0;
        }
        else if (a == b) {
            a = a + b;
            b = 0;
            if (c == d) {
                c = c + d;
                d = 0;
            }
        }
        else if (b == 0 && a == c) {
            a = a + c;
            c = 0;
        }
        else if (c == 0 && b == d) {
            b = b + d;
            d = 0;
        }
        else if (b == c) {
            b = b + c;
            c = 0;
        }
        else if (c == d) {
            c = c + d;
            d = 0;
        }


        //循环将0后移
        int temp = 0;
        for (int k = 0; k < 3; k++) {
            if (a == 0) {
                temp = a;
                a = b;
                b = temp;
            }
            if (b == 0) {
                temp = b;
                b = c;
                c = temp;
            }
            if (c == 0) {
                temp = c;
                c = d;
                d = temp;
            }
        }
        //更新map
        map[0][i] = d;
        map[1][i] = c;
        map[2][i] = b;
        map[3][i] = a;
    }
}
/***************************
    UP
****************************/
void toUP(TYPE ** map) {
    int a = 0, b = 0, c = 0, d = 0;
    for (int i = 0; i < 4; i++) {//遍历每一行
        a = map[0][i];
        b = map[1][i];
        c = map[2][i];
        d = map[3][i];

        if (b == 0 && c == 0 && a == d) {
            a = a + d;
            d = 0;
        }
        else if (a == b) {
            a = a + b;
            b = 0;
            if (c == d) {
                c = c + d;
                d = 0;
            }
        }
        else if (b == 0 && a == c) {
            a = a + c;
            c = 0;
        }
        else if (c == 0 && b == d) {
            b = b + d;
            d = 0;
        }
        else if (b == c) {
            b = b + c;
            c = 0;
        }
        else if (c == d) {
            c = c + d;
            d = 0;
        }


        //循环将0后移
        int temp = 0;
        for (int k = 0; k < 3; k++) {
            if (a == 0) {
                temp = a;
                a = b;
                b = temp;
            }
            if (b == 0) {
                temp = b;
                b = c;
                c = temp;
            }
            if (c == 0) {
                temp = c;
                c = d;
                d = temp;
            }
        }
        //更新map
        map[0][i] = a;
        map[1][i] = b;
        map[2][i] = c;
        map[3][i] = d;
    }
}
/***************************
    游戏规则
****************************/
void GameRule() {
    int * map[4];
    //第一次进入游戏初始化
    InitGame(map, 4);

    do {
        system("cls");
        Output(map, 4);
        switch (_getch()) {
        case LEFT://printf("LEFT\n");
            toLEFT(map);
            RandNum(map, 4);
            break;
        case RIGHT://printf("RIGHT\n");
            toRIGHT(map);
            RandNum(map, 4);
            break;
        case DOWN://printf("DOWN\n");
            toDOWN(map);
            RandNum(map, 4);
            break;
        case UP://printf("UP\n");
            toUP(map);
            RandNum(map, 4);
            break;
        case RESTART://重置游戏a
            //system("cls");
            RInitGame(map, 4);
            break;
        case EXIT://退出游戏d
            break;
        }
    } while (true);
}
/*
int main() {
    GameRule(4);
    return 0;
}
*/





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // int * map[4];
    ui->setupUi(this);
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Btn_click()));
   // connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(InitGameMap(map)));
    InitGame(map,4);

    if(map[0][0]!=0){
        ui->label_3->setText(QString::number(map[0][0],10));

        if(map[0][0]%32==0){
            ui->label_3->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[0][0]%16==0){
            ui->label_3->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[0][0]%8==0){
            ui->label_3->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[0][0]%4==0){
            ui->label_3->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[0][0]%2==0){
            ui->label_3->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_3->setText("");
        ui->label_3->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[0][1]!=0){
         ui->label_4->setText(QString::number(map[0][1],10));

         if(map[0][1]%32==0){
             ui->label_4->setStyleSheet("background-color:rgb(240, 80, 0)");
         }else if(map[0][1]%16==0){
             ui->label_4->setStyleSheet("background-color:rgb(218, 145, 0)");
         }else if(map[0][1]%8==0){
             ui->label_4->setStyleSheet("background-color:rgb(255, 170, 0)");
         }else if(map[0][1]%4==0){
             ui->label_4->setStyleSheet("background-color:rgb(235, 235, 176)");
         }else if(map[0][1]%2==0){
             ui->label_4->setStyleSheet("background-color:rgb(249, 249, 187)");
         }
    }
    else{
         ui->label_4->setText("");
         ui->label_4->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[0][2]!=0){
        ui->label_2->setText(QString::number(map[0][2],10));

        if(map[0][2]%32==0){
            ui->label_2->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[0][2]%16==0){
            ui->label_2->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[0][2]%8==0){
            ui->label_2->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[0][2]%4==0){
            ui->label_2->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[0][2]%2==0){
            ui->label_2->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_2->setText("");
         ui->label_2->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[0][3]!=0){
    ui->label_5->setText(QString::number(map[0][3],10));
    if(map[0][3]%32==0){
        ui->label_5->setStyleSheet("background-color:rgb(240, 80, 0)");
    }else if(map[0][3]%16==0){
        ui->label_5->setStyleSheet("background-color:rgb(218, 145, 0)");
    }else if(map[0][3]%8==0){
        ui->label_5->setStyleSheet("background-color:rgb(255, 170, 0)");
    }else if(map[0][3]%4==0){
        ui->label_5->setStyleSheet("background-color:rgb(235, 235, 176)");
    }else if(map[0][3]%2==0){
        ui->label_5->setStyleSheet("background-color:rgb(249, 249, 187)");
    }
    }
    else{
        ui->label_5->setText("");
        ui->label_5->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[1][0]!=0){
        ui->label_6->setText(QString::number(map[1][0],10));
        if(map[1][0]%32==0){
            ui->label_6->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][0]%16==0){
            ui->label_6->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][0]%8==0){
            ui->label_6->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][0]%4==0){
            ui->label_6->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][0]%2==0){
            ui->label_6->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_6->setText("");
         ui->label_6->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[1][1]!=0){
        ui->label_7->setText(QString::number(map[1][1],10));
        if(map[1][1]%32==0){
            ui->label_7->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][1]%16==0){
            ui->label_7->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][1]%8==0){
            ui->label_7->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][1]%4==0){
            ui->label_7->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][1]%2==0){
            ui->label_7->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_7->setText("");
        ui->label_7->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[1][2]!=0){
        ui->label_8->setText(QString::number(map[1][2],10));
        if(map[1][2]%32==0){
            ui->label_8->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][2]%16==0){
            ui->label_8->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][2]%8==0){
            ui->label_8->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][2]%4==0){
            ui->label_8->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][2]%2==0){
            ui->label_8->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_8->setText("");
        ui->label_8->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[1][3]!=0){
        ui->label_9->setText(QString::number(map[1][3],10));
        if(map[1][3]%32==0){
            ui->label_9->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][3]%16==0){
            ui->label_9->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][3]%8==0){
            ui->label_9->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][3]%4==0){
            ui->label_9->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][3]%2==0){
            ui->label_9->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_9->setText("");
        ui->label_9->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[2][0]!=0){
        ui->label_10->setText(QString::number(map[2][0],10));
        if(map[2][0]%32==0){
            ui->label_10->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][0]%16==0){
            ui->label_10->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][0]%8==0){
            ui->label_10->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][0]%4==0){
            ui->label_10->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][0]%2==0){
            ui->label_10->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_10->setText("");
        ui->label_10->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[2][1]!=0){
        ui->label_11->setText(QString::number(map[2][1],10));
        if(map[2][1]%32==0){
            ui->label_11->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][1]%16==0){
            ui->label_11->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][1]%8==0){
            ui->label_11->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][1]%4==0){
            ui->label_11->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][1]%2==0){
            ui->label_11->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_11->setText("");
        ui->label_11->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[2][2]!=0){
        ui->label_12->setText(QString::number(map[2][2],10));
        if(map[2][2]%32==0){
            ui->label_12->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][2]%16==0){
            ui->label_12->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][2]%8==0){
            ui->label_12->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][2]%4==0){
            ui->label_12->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][2]%2==0){
            ui->label_12->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_12->setText("");
        ui->label_12->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[2][3]!=0){
        ui->label_13->setText(QString::number(map[2][3],10));
        if(map[2][3]%32==0){
            ui->label_13->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][3]%16==0){
            ui->label_13->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][3]%8==0){
            ui->label_13->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][3]%4==0){
            ui->label_13->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][3]%2==0){
            ui->label_13->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_13->setText("");
        ui->label_13->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[3][0]!=0){
        ui->label_14->setText(QString::number(map[3][0],10));
        if(map[3][0]%32==0){
            ui->label_14->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][0]%16==0){
            ui->label_14->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][0]%8==0){
            ui->label_14->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][0]%4==0){
            ui->label_14->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][0]%2==0){
            ui->label_14->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_14->setText("");
        ui->label_14->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[3][1]!=0){
        ui->label_15->setText(QString::number(map[3][1],10));
        if(map[3][1]%32==0){
            ui->label_15->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][1]%16==0){
            ui->label_15->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][1]%8==0){
            ui->label_15->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][1]%4==0){
            ui->label_15->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][1]%2==0){
            ui->label_15->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_15->setText("");
        ui->label_15->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[3][2]!=0){
        ui->label_16->setText(QString::number(map[3][2],10));
        if(map[3][2]%32==0){
            ui->label_16->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][2]%16==0){
            ui->label_16->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][2]%8==0){
            ui->label_16->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][2]%4==0){
            ui->label_16->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][2]%2==0){
            ui->label_16->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_16->setText("");
        ui->label_16->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[3][3]!=0){
        ui->label_17->setText(QString::number(map[3][3],10));
        if(map[3][3]%32==0){
            ui->label_17->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][3]%16==0){
            ui->label_17->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][3]%8==0){
            ui->label_17->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][3]%4==0){
            ui->label_17->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][3]%2==0){
            ui->label_17->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_17->setText("");
        ui->label_17->setStyleSheet("background-color:rgb(209, 209, 157)");
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

/**
 * @brief MainWindow::MainWindow
 * @param parent
 * 控制方向键读取
 * 返回
 * 1 LEFT
 * 2 RITHT
 * 3 DOWN
 * 4 UP
 */

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(event->key()==Qt::Key_Left){
        ui->label->setText("<font color=red size=100><b>向左</b></font>");
        toLEFT(map);
        RandNum(map,4);
    }
    if(event->key()==Qt::Key_Right){
        ui->label->setText("<font color=red size=100><b>向右</b></font>");
        toRIGHT(map);
        RandNum(map, 4);
    }
    if(event->key()==Qt::Key_Down){
        ui->label->setText("<font color=red size=100><b>向下</b></font>");
        toDOWN(map);
        RandNum(map, 4);
    }
    if(event->key()==Qt::Key_Up){
        ui->label->setText("<font color=red size=100><b>向上</b></font>");
        toUP(map);
        RandNum(map, 4);
    }
    if(map[0][0]!=0){
        ui->label_3->setText(QString::number(map[0][0],10));

        if(map[0][0]%32==0){
            ui->label_3->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[0][0]%16==0){
            ui->label_3->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[0][0]%8==0){
            ui->label_3->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[0][0]%4==0){
            ui->label_3->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[0][0]%2==0){
            ui->label_3->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_3->setText("");
        ui->label_3->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[0][1]!=0){
         ui->label_4->setText(QString::number(map[0][1],10));

         if(map[0][1]%32==0){
             ui->label_4->setStyleSheet("background-color:rgb(240, 80, 0)");
         }else if(map[0][1]%16==0){
             ui->label_4->setStyleSheet("background-color:rgb(218, 145, 0)");
         }else if(map[0][1]%8==0){
             ui->label_4->setStyleSheet("background-color:rgb(255, 170, 0)");
         }else if(map[0][1]%4==0){
             ui->label_4->setStyleSheet("background-color:rgb(235, 235, 176)");
         }else if(map[0][1]%2==0){
             ui->label_4->setStyleSheet("background-color:rgb(249, 249, 187)");
         }
    }
    else{
         ui->label_4->setText("");
         ui->label_4->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[0][2]!=0){
        ui->label_2->setText(QString::number(map[0][2],10));

        if(map[0][2]%32==0){
            ui->label_2->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[0][2]%16==0){
            ui->label_2->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[0][2]%8==0){
            ui->label_2->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[0][2]%4==0){
            ui->label_2->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[0][2]%2==0){
            ui->label_2->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_2->setText("");
         ui->label_2->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[0][3]!=0){
    ui->label_5->setText(QString::number(map[0][3],10));
    if(map[0][3]%32==0){
        ui->label_5->setStyleSheet("background-color:rgb(240, 80, 0)");
    }else if(map[0][3]%16==0){
        ui->label_5->setStyleSheet("background-color:rgb(218, 145, 0)");
    }else if(map[0][3]%8==0){
        ui->label_5->setStyleSheet("background-color:rgb(255, 170, 0)");
    }else if(map[0][3]%4==0){
        ui->label_5->setStyleSheet("background-color:rgb(235, 235, 176)");
    }else if(map[0][3]%2==0){
        ui->label_5->setStyleSheet("background-color:rgb(249, 249, 187)");
    }
    }
    else{
        ui->label_5->setText("");
        ui->label_5->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[1][0]!=0){
        ui->label_6->setText(QString::number(map[1][0],10));
        if(map[1][0]%32==0){
            ui->label_6->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][0]%16==0){
            ui->label_6->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][0]%8==0){
            ui->label_6->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][0]%4==0){
            ui->label_6->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][0]%2==0){
            ui->label_6->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_6->setText("");
         ui->label_6->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[1][1]!=0){
        ui->label_7->setText(QString::number(map[1][1],10));
        if(map[1][1]%32==0){
            ui->label_7->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][1]%16==0){
            ui->label_7->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][1]%8==0){
            ui->label_7->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][1]%4==0){
            ui->label_7->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][1]%2==0){
            ui->label_7->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_7->setText("");
        ui->label_7->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[1][2]!=0){
        ui->label_8->setText(QString::number(map[1][2],10));
        if(map[1][2]%32==0){
            ui->label_8->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][2]%16==0){
            ui->label_8->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][2]%8==0){
            ui->label_8->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][2]%4==0){
            ui->label_8->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][2]%2==0){
            ui->label_8->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_8->setText("");
        ui->label_8->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[1][3]!=0){
        ui->label_9->setText(QString::number(map[1][3],10));
        if(map[1][3]%32==0){
            ui->label_9->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][3]%16==0){
            ui->label_9->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][3]%8==0){
            ui->label_9->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][3]%4==0){
            ui->label_9->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][3]%2==0){
            ui->label_9->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_9->setText("");
        ui->label_9->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[2][0]!=0){
        ui->label_10->setText(QString::number(map[2][0],10));
        if(map[2][0]%32==0){
            ui->label_10->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][0]%16==0){
            ui->label_10->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][0]%8==0){
            ui->label_10->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][0]%4==0){
            ui->label_10->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][0]%2==0){
            ui->label_10->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_10->setText("");
        ui->label_10->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[2][1]!=0){
        ui->label_11->setText(QString::number(map[2][1],10));
        if(map[2][1]%32==0){
            ui->label_11->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][1]%16==0){
            ui->label_11->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][1]%8==0){
            ui->label_11->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][1]%4==0){
            ui->label_11->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][1]%2==0){
            ui->label_11->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_11->setText("");
        ui->label_11->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[2][2]!=0){
        ui->label_12->setText(QString::number(map[2][2],10));
        if(map[2][2]%32==0){
            ui->label_12->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][2]%16==0){
            ui->label_12->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][2]%8==0){
            ui->label_12->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][2]%4==0){
            ui->label_12->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][2]%2==0){
            ui->label_12->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_12->setText("");
        ui->label_12->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[2][3]!=0){
        ui->label_13->setText(QString::number(map[2][3],10));
        if(map[2][3]%32==0){
            ui->label_13->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][3]%16==0){
            ui->label_13->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][3]%8==0){
            ui->label_13->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][3]%4==0){
            ui->label_13->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][3]%2==0){
            ui->label_13->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_13->setText("");
        ui->label_13->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[3][0]!=0){
        ui->label_14->setText(QString::number(map[3][0],10));
        if(map[3][0]%32==0){
            ui->label_14->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][0]%16==0){
            ui->label_14->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][0]%8==0){
            ui->label_14->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][0]%4==0){
            ui->label_14->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][0]%2==0){
            ui->label_14->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_14->setText("");
        ui->label_14->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[3][1]!=0){
        ui->label_15->setText(QString::number(map[3][1],10));
        if(map[3][1]%32==0){
            ui->label_15->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][1]%16==0){
            ui->label_15->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][1]%8==0){
            ui->label_15->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][1]%4==0){
            ui->label_15->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][1]%2==0){
            ui->label_15->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_15->setText("");
        ui->label_15->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[3][2]!=0){
        ui->label_16->setText(QString::number(map[3][2],10));
        if(map[3][2]%32==0){
            ui->label_16->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][2]%16==0){
            ui->label_16->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][2]%8==0){
            ui->label_16->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][2]%4==0){
            ui->label_16->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][2]%2==0){
            ui->label_16->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_16->setText("");
        ui->label_16->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[3][3]!=0){
        ui->label_17->setText(QString::number(map[3][3],10));
        if(map[3][3]%32==0){
            ui->label_17->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][3]%16==0){
            ui->label_17->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][3]%8==0){
            ui->label_17->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][3]%4==0){
            ui->label_17->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][3]%2==0){
            ui->label_17->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_17->setText("");
        ui->label_17->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
}

///槽实现
void MainWindow::Btn_click(){


    //ui->label->setText("<font color=red size=100><b>员工资料基本维护</b></font>");


   // int * map[4];
    RInitGame(map,4);



    if(map[0][0]!=0){
        ui->label_3->setText(QString::number(map[0][0],10));

        if(map[0][0]%32==0){
            ui->label_3->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[0][0]%16==0){
            ui->label_3->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[0][0]%8==0){
            ui->label_3->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[0][0]%4==0){
            ui->label_3->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[0][0]%2==0){
            ui->label_3->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_3->setText("");
        ui->label_3->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[0][1]!=0){
         ui->label_4->setText(QString::number(map[0][1],10));

         if(map[0][1]%32==0){
             ui->label_4->setStyleSheet("background-color:rgb(240, 80, 0)");
         }else if(map[0][1]%16==0){
             ui->label_4->setStyleSheet("background-color:rgb(218, 145, 0)");
         }else if(map[0][1]%8==0){
             ui->label_4->setStyleSheet("background-color:rgb(255, 170, 0)");
         }else if(map[0][1]%4==0){
             ui->label_4->setStyleSheet("background-color:rgb(235, 235, 176)");
         }else if(map[0][1]%2==0){
             ui->label_4->setStyleSheet("background-color:rgb(249, 249, 187)");
         }
    }
    else{
         ui->label_4->setText("");
         ui->label_4->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[0][2]!=0){
        ui->label_2->setText(QString::number(map[0][2],10));

        if(map[0][2]%32==0){
            ui->label_2->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[0][2]%16==0){
            ui->label_2->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[0][2]%8==0){
            ui->label_2->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[0][2]%4==0){
            ui->label_2->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[0][2]%2==0){
            ui->label_2->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_2->setText("");
         ui->label_2->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[0][3]!=0){
    ui->label_5->setText(QString::number(map[0][3],10));
    if(map[0][3]%32==0){
        ui->label_5->setStyleSheet("background-color:rgb(240, 80, 0)");
    }else if(map[0][3]%16==0){
        ui->label_5->setStyleSheet("background-color:rgb(218, 145, 0)");
    }else if(map[0][3]%8==0){
        ui->label_5->setStyleSheet("background-color:rgb(255, 170, 0)");
    }else if(map[0][3]%4==0){
        ui->label_5->setStyleSheet("background-color:rgb(235, 235, 176)");
    }else if(map[0][3]%2==0){
        ui->label_5->setStyleSheet("background-color:rgb(249, 249, 187)");
    }
    }
    else{
        ui->label_5->setText("");
        ui->label_5->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[1][0]!=0){
        ui->label_6->setText(QString::number(map[1][0],10));
        if(map[1][0]%32==0){
            ui->label_6->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][0]%16==0){
            ui->label_6->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][0]%8==0){
            ui->label_6->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][0]%4==0){
            ui->label_6->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][0]%2==0){
            ui->label_6->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_6->setText("");
         ui->label_6->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[1][1]!=0){
        ui->label_7->setText(QString::number(map[1][1],10));
        if(map[1][1]%32==0){
            ui->label_7->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][1]%16==0){
            ui->label_7->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][1]%8==0){
            ui->label_7->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][1]%4==0){
            ui->label_7->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][1]%2==0){
            ui->label_7->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_7->setText("");
        ui->label_7->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[1][2]!=0){
        ui->label_8->setText(QString::number(map[1][2],10));
        if(map[1][2]%32==0){
            ui->label_8->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][2]%16==0){
            ui->label_8->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][2]%8==0){
            ui->label_8->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][2]%4==0){
            ui->label_8->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][2]%2==0){
            ui->label_8->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_8->setText("");
        ui->label_8->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[1][3]!=0){
        ui->label_9->setText(QString::number(map[1][3],10));
        if(map[1][3]%32==0){
            ui->label_9->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[1][3]%16==0){
            ui->label_9->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[1][3]%8==0){
            ui->label_9->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[1][3]%4==0){
            ui->label_9->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[1][3]%2==0){
            ui->label_9->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_9->setText("");
        ui->label_9->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[2][0]!=0){
        ui->label_10->setText(QString::number(map[2][0],10));
        if(map[2][0]%32==0){
            ui->label_10->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][0]%16==0){
            ui->label_10->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][0]%8==0){
            ui->label_10->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][0]%4==0){
            ui->label_10->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][0]%2==0){
            ui->label_10->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_10->setText("");
        ui->label_10->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[2][1]!=0){
        ui->label_11->setText(QString::number(map[2][1],10));
        if(map[2][1]%32==0){
            ui->label_11->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][1]%16==0){
            ui->label_11->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][1]%8==0){
            ui->label_11->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][1]%4==0){
            ui->label_11->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][1]%2==0){
            ui->label_11->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_11->setText("");
        ui->label_11->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[2][2]!=0){
        ui->label_12->setText(QString::number(map[2][2],10));
        if(map[2][2]%32==0){
            ui->label_12->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][2]%16==0){
            ui->label_12->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][2]%8==0){
            ui->label_12->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][2]%4==0){
            ui->label_12->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][2]%2==0){
            ui->label_12->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_12->setText("");
        ui->label_12->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[2][3]!=0){
        ui->label_13->setText(QString::number(map[2][3],10));
        if(map[2][3]%32==0){
            ui->label_13->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[2][3]%16==0){
            ui->label_13->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[2][3]%8==0){
            ui->label_13->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[2][3]%4==0){
            ui->label_13->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[2][3]%2==0){
            ui->label_13->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_13->setText("");
        ui->label_13->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

    if(map[3][0]!=0){
        ui->label_14->setText(QString::number(map[3][0],10));
        if(map[3][0]%32==0){
            ui->label_14->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][0]%16==0){
            ui->label_14->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][0]%8==0){
            ui->label_14->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][0]%4==0){
            ui->label_14->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][0]%2==0){
            ui->label_14->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_14->setText("");
        ui->label_14->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[3][1]!=0){
        ui->label_15->setText(QString::number(map[3][1],10));
        if(map[3][1]%32==0){
            ui->label_15->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][1]%16==0){
            ui->label_15->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][1]%8==0){
            ui->label_15->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][1]%4==0){
            ui->label_15->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][1]%2==0){
            ui->label_15->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_15->setText("");
        ui->label_15->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[3][2]!=0){
        ui->label_16->setText(QString::number(map[3][2],10));
        if(map[3][2]%32==0){
            ui->label_16->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][2]%16==0){
            ui->label_16->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][2]%8==0){
            ui->label_16->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][2]%4==0){
            ui->label_16->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][2]%2==0){
            ui->label_16->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_16->setText("");
        ui->label_16->setStyleSheet("background-color:rgb(209, 209, 157)");
    }
    if(map[3][3]!=0){
        ui->label_17->setText(QString::number(map[3][3],10));
        if(map[3][3]%32==0){
            ui->label_17->setStyleSheet("background-color:rgb(240, 80, 0)");
        }else if(map[3][3]%16==0){
            ui->label_17->setStyleSheet("background-color:rgb(218, 145, 0)");
        }else if(map[3][3]%8==0){
            ui->label_17->setStyleSheet("background-color:rgb(255, 170, 0)");
        }else if(map[3][3]%4==0){
            ui->label_17->setStyleSheet("background-color:rgb(235, 235, 176)");
        }else if(map[3][3]%2==0){
            ui->label_17->setStyleSheet("background-color:rgb(249, 249, 187)");
        }
    }
    else{
        ui->label_17->setText("");
        ui->label_17->setStyleSheet("background-color:rgb(209, 209, 157)");
    }

}

