#pragma once

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>


using namespace std;

//符号的定义
#define ROW 3
#define COL 3

//函数的声明

//初始化棋盘的
void InitBoard(char board[ROW][COL],int row,int col);

//打印棋盘的函数
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家下棋
void PlayerMove(char board[][COL],int row,int col);
//电脑下棋
void ComputeMove(char board[ROW][COL], int row, int col);
//判断输赢

//玩家赢-*
//电脑赢-#
//平局-Q
//游戏继续-C
char Iswin(char board[ROW][COL],int row,int col);