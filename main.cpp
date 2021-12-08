
#include "game.h"



void menu() {
	cout << "*********************************" << endl;
	cout << "****         1.play          ****" << endl;
	cout << "****         0.exit          ****" << endl;
	cout << "*********************************" << endl;
}



void game() {
	//存储数据，二维数组
	char board[ROW][COL];
	//初始化期盼
	InitBoard(board,ROW,COL);
	//打印下期盼,打印数组内容
	DisplayBoard(board,ROW,COL);
	char ret = 0;//接收游戏状态

	while (1) {
		//玩家下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢得游戏
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
		//电脑下棋
		ComputeMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢得游戏

		ret = Iswin(board,ROW,COL);
		if (ret != 'C')
			break;

	}
	if (ret == '*') {
		cout << "玩家赢了" << endl;
	}
	else if (ret == '#') {
		cout << "电脑赢了" << endl;
	}
	else if (ret == 'Q') {
		cout << "平局" << endl;	
	}
	DisplayBoard(board, ROW, COL);

}

int main() {
	int input = 0;
	srand((unsigned int)time(NULL));

	menu();
	cout << "请选择：>" << endl;
	do {
		
		cin >> input;
		switch (input) {
		case 1:
			cout << "三子棋游戏" << endl;
			game();
			break;
		case 0:
			cout << "退出游戏" << endl;
			break;
		default:
			cout << "选择错误，重新选择" << endl;
			break;

		}
	} while (input);
	

	return 0;

}