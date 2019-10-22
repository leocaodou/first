#include <iostream>
#include <vector>
#include <string>
#include <curses.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

//���Ӻ�����Ŀ�Ϳ��
#define   N    4
#define WIDTH  5

//���ó�ʼ�������ָ���
#define STNUM   1

//������Ϸʤ������
#define TARGET  2048

//״̬��
#define WIN  0
#define LOSE 1
#define NORM 2
#define QUIT 3

//2048�ඨ��
class Game2048
{
public:
	Game2048() {
		setData();
	}

	//��ȡ��Ϸ״̬
	int getStatus() {
		return status;
	}
	
	//��ȡ�û����룬����״̬
	void getChar() {
		char ch = getch();
		if (ch>='a' && ch<='z')
			ch = ch - 32;

		//���������ƶ�������Ϸ
		if (status == NORM) {
			//״̬����
			bool update = false;
			if (ch == 'A') {
				update = moveLeft();
			} else if (ch == 'S') {
				rotate();
				update = moveLeft();
				rotate();
				rotate();
				rotate();
			} else if (ch == 'D') {
				rotate();
				rotate();
				update = moveLeft();
				rotate();
				rotate();
			} else if (ch == 'W') {
				rotate();
				rotate();
				rotate();
				update = moveLeft();
				rotate();
			}

			if (update) {
				randNew(STNUM);
				if (isOver()) {
					status = LOSE;
				}
			}
		}
		
		//�˳���ˢ��
		if (ch == 'Q')
			status = QUIT;
		else if (ch == 'R')
			restart();
		else if (ch == 'N')
			dataSave();
		else if (ch == 'M')
			dataLoad();
	}

	//������Ϸ����
	void draw() {
		clear();                    //������Ļ
        const int xoffset = 5;     //���ú�ƫ����
		const int yoffset = 40;     //������ƫ����

		//����ż���У�ȫ��Ϊ��-�����ٲ����滻Ϊ��+��
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < N*WIDTH; j++) {
				mvaddch(2*i + xoffset, j + yoffset, '-');
			}
			for (int j = 0; j <= N; j++) {
				mvaddch(2*i + xoffset, j*WIDTH + yoffset, '+');
			}
		}

		//���������У������Ҷ���
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mvaddch(2*i + 1 + xoffset, j*WIDTH + yoffset, '|');	
				drawNum(2*i + 1 + xoffset, (j+1)*WIDTH + yoffset, data[i][j]);
			}	
			mvaddch(2*i + 1 + xoffset, N*WIDTH + yoffset, '|');	
		}
		
		//������Ϸ�����������÷�
		string strOperate = "W(UP),S(DOWN),A(LEFT),D(RIGHT),R(RESTART),N(SAVE),M(LOAD),Q(QUIT)";
		mvprintw(2*N + 3 + xoffset, N/2*WIDTH + yoffset - strOperate.length()/2, strOperate.data());

		//���Ƶ÷ּ���߷�
		mvprintw(N/2 + xoffset, yoffset/4, (" max:  "+to_string(max)).data());
		mvprintw(3*N/2 + xoffset, yoffset/4, ("score: "+to_string(score)).data());

		//����״̬��Ϣ
		string strStatus;
		if (status == WIN)
			strStatus = "YOU  WIN";
		if (status == LOSE)
			strStatus = "YOU LOSE";
		mvprintw(2*N + 6 + xoffset, N/2*WIDTH + yoffset - strStatus.length()/2, strStatus.data());
		
		//���������û�����R
		if (status != NORM) {
			string strStart = "PRESS R TO START !";
			mvprintw(2*N + 7 + xoffset, N/2*WIDTH + yoffset - strStart.length()/2, strStart.data());
			start = false;
		}
	}




private:
	int data[N][N];
	int save[N][N];
	int status = -1;
	int score = 0;
	int Score = 0;
	int max = 0;
	bool start = true;

	//���ʼ��ʱ��Ϸ��������
	void setData() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				data[i][j] = 0;
				save[i][j] = 0;
			}
		}
	}

	//�Ҷ����������
	void drawNum(int x, int y, int num) {
		while (num > 0){
			mvaddch(x, --y, num%10+'0');
			num = num / 10;
		}
	}

	//���¿�ʼ��Ϸ����
	void restart() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				data[i][j] = 0;
			}
		}

		//������Χ�Զ�����Ϊ1
		if (STNUM>=N*N || STNUM<0)
			randNew(1);
		else
			randNew(STNUM);
		
		score = 0;
		status = NORM;
	}

	//����������������
	bool randNew(int num) {
		for (int cnt = 0; cnt < num; cnt++) {
			vector <int> emptyPos;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (data[i][j] == 0)
						emptyPos.push_back(i*N+j);
				}
			}
			
			if (emptyPos.size() == 0)
				return false;

			int pos = emptyPos[rand()%emptyPos.size()];
			data[pos/N][pos%N] = (rand()%10==0 ? 4:2);
		}

		return true;
	}

	//��Ϸ���Ʋ���
	bool moveLeft() {
		int compare[N][N];
		for (int i = 0; i < N; i++) {
			int cur = 0;         //�Ƚ�ֵ
			int pos = 0;         //���λ��

			for (int j = 0; j < N; j++) {
				compare[i][j] = data[i][j];

				//�Ӳ�Ϊ0��λ�ÿ�ʼ
				if (data[i][j] == 0)
					continue;
		
				//��cur��Ϊ0��ʼ�Ƚ����
				if (cur == 0) {
					cur = data[i][j];
				}else {
					if (data[i][j] == cur) {
						data[i][pos] = cur<<1;
						score += data[i][pos];
						cur = 0;
						if (data[i][pos] == TARGET)
							status = WIN;
						if (max <= score)
							max = score;
					}else {
						data[i][pos] = cur;
						cur = data[i][j];
					}

					//���λ������һλ
					pos++;
				}

				//�Ѿ�������ӣ���λ������Ϊ0
				data[i][j] = 0;
			}

			//�Ƚ�ֵ��Ϊ0�����
			if (cur != 0)
				data[i][pos] = cur;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (compare[i][j] != data[i][j])
					return true;
			}
		}
		return false;
	}

	//˳ʱ����ת90��
	void rotate() {
		int tempdata[N][N];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tempdata[i][j] = data[N-j-1][i];
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				data[i][j] = tempdata[i][j];
			}
		}
	}

	//�ж���Ϸ�Ƿ����
	bool isOver() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (data[i][j] == 0)
					return false;
				if (i+1<N && data[i][j]==data[i+1][j])
					return false;
				if (j+1<N && data[i][j]==data[i][j+1])
					return false;
			}
		}
		return true;
	}

	//��¼��ǰ��Ϸ��¼
	void dataSave() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				save[i][j] = data[i][j];
			}
		}
		Score = score;
	}

	//��ȡ֮ǰ��Ϸ��¼
	void dataLoad() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				data[i][j] = save[i][j];
			}
		}
		score = Score;
		status = NORM;
	}
};


// ��ʼ��������ncurses
void initialize() {
    initscr();            //��ʼ��ncurses
    cbreak();             //���ð���ֱ�ӽ���
    noecho();             //���ð���������
    curs_set(0);          //���ù�겻�ɼ�
    srand(time(NULL));    //���������
}

// �ָ�ncurses״̬
void shutdown() {
    endwin();              //�ָ��ն˻�״̬        
}


int main() {
    initialize();

	Game2048 game;
    do {
		game.draw();
		game.getChar();
	}while(game.getStatus() != QUIT);

    shutdown();
}

