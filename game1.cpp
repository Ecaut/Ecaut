#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			board[i][j] = ' ';

		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << "  " << board[i][j];
			if (j < col - 1)
				cout << "|";

		}
		cout << endl;
		if (i < row - 1)
			//cout << "---|---|---" << endl;
			for (int j = 0; j < col; j++) {
				cout << "---";
				if (j < col - 1)
					cout << "|";
			}
		cout << endl;
	}
}

void PlayerMove(char board[][COL],int row,int col) {
	int x = 0, y = 0;
	
	while (1) {
		cout << "玩家走" << endl;
		cout << "请输入下棋的坐标：>" << endl;
		
		cin >> x >> y;
		//判断坐标合法性
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			//下棋,判断坐标是否被占用
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = '*';
				break;
			}
			else {
				cout << "坐标被占用，请重新输入" << endl;

			}

		}
		else {
			cout << "坐标非法，请重新输入" << endl;

		}
	}
}

void ComputeMove(char board[ROW][COL], int row, int col) {
	
	cout << "电脑走<" << endl;
	while (1) {
		int x = rand() % row, y = rand() % col;   //不用判断
		if (board[x][y] == ' ') {
			board[x][y] = '#';
			break;

		}
	}

}

int IsFull(char board[ROW][COL], int row, int col) {
	int i = 0, j = 0;
	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			if (board[i][j] == ' ') {
				return 0;//棋盘没满
			}	
		}
	}
	return 1;

}

//判断输赢
char Iswin(char board[ROW][COL], int row, int col) {
	int i = 0, j = 0;
	//判断三行
	for (i = 0; i < row; i++) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}
	//判断三列
	for (j = 0; j < col; j++) {
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
			return board[1][j];
	}
	if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] !=' ') || (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')){
		return board[1][1];
	}
	
	//判断平局
	//如果期盼满了返回1，不满返回0
	int ret = IsFull(board,row,col);
		if (ret == 1) {
			return 'Q';
		}
	
	//继续
	return 'C';

}
	
