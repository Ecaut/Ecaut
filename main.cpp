
#include "game.h"



void menu() {
	cout << "*********************************" << endl;
	cout << "****         1.play          ****" << endl;
	cout << "****         0.exit          ****" << endl;
	cout << "*********************************" << endl;
}



void game() {
	//�洢���ݣ���ά����
	char board[ROW][COL];
	//��ʼ������
	InitBoard(board,ROW,COL);
	//��ӡ������,��ӡ��������
	DisplayBoard(board,ROW,COL);
	char ret = 0;//������Ϸ״̬

	while (1) {
		//�������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ����Ϸ
		ret = Iswin(board, ROW, COL);
		if (ret != 'C')
			break;
		//��������
		ComputeMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ����Ϸ

		ret = Iswin(board,ROW,COL);
		if (ret != 'C')
			break;

	}
	if (ret == '*') {
		cout << "���Ӯ��" << endl;
	}
	else if (ret == '#') {
		cout << "����Ӯ��" << endl;
	}
	else if (ret == 'Q') {
		cout << "ƽ��" << endl;	
	}
	DisplayBoard(board, ROW, COL);

}

int main() {
	int input = 0;
	srand((unsigned int)time(NULL));

	menu();
	cout << "��ѡ��>" << endl;
	do {
		
		cin >> input;
		switch (input) {
		case 1:
			cout << "��������Ϸ" << endl;
			game();
			break;
		case 0:
			cout << "�˳���Ϸ" << endl;
			break;
		default:
			cout << "ѡ���������ѡ��" << endl;
			break;

		}
	} while (input);
	

	return 0;

}