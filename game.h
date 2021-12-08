#pragma once

#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>


using namespace std;

//���ŵĶ���
#define ROW 3
#define COL 3

//����������

//��ʼ�����̵�
void InitBoard(char board[ROW][COL],int row,int col);

//��ӡ���̵ĺ���
void DisplayBoard(char board[ROW][COL], int row, int col);

//�������
void PlayerMove(char board[][COL],int row,int col);
//��������
void ComputeMove(char board[ROW][COL], int row, int col);
//�ж���Ӯ

//���Ӯ-*
//����Ӯ-#
//ƽ��-Q
//��Ϸ����-C
char Iswin(char board[ROW][COL],int row,int col);