#include <iostream>
#include <vector>
#include <string>
#include <curses.h>
#include <cstdlib>
#include <cstdio>
#include <ctime>

using namespace std;

//格子横纵数目和宽度
#define   N    4
#define WIDTH  5

//设置初始化新数字个数
#define STNUM   1

//设置游戏胜利条件
#define TARGET  2048

//状态表
#define WIN  0
#define LOSE 1
#define NORM 2
#define QUIT 3

//2048类定义
class Game2048
{
public:
	Game2048() {
		setData();
	}

	//获取游戏状态
	int getStatus() {
		return status;
	}
	
	//获取用户输入，设置状态
	void getChar() {
		char ch = getch();
		if (ch>='a' && ch<='z')
			ch = ch - 32;

		//上下左右移动进行游戏
		if (status == NORM) {
			//状态更新
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
		
		//退出和刷新
		if (ch == 'Q')
			status = QUIT;
		else if (ch == 'R')
			restart();
		else if (ch == 'N')
			dataSave();
		else if (ch == 'M')
			dataLoad();
	}

	//绘制游戏界面
	void draw() {
		clear();                    //清理屏幕
        const int xoffset = 5;     //设置横偏移量
		const int yoffset = 40;     //设置纵偏移量

		//绘制偶数行，全置为‘-’后再部分替换为‘+’
		for (int i = 0; i <= N; i++) {
			for (int j = 0; j < N*WIDTH; j++) {
				mvaddch(2*i + xoffset, j + yoffset, '-');
			}
			for (int j = 0; j <= N; j++) {
				mvaddch(2*i + xoffset, j*WIDTH + yoffset, '+');
			}
		}

		//绘制奇数行，数字右对齐
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				mvaddch(2*i + 1 + xoffset, j*WIDTH + yoffset, '|');	
				drawNum(2*i + 1 + xoffset, (j+1)*WIDTH + yoffset, data[i][j]);
			}	
			mvaddch(2*i + 1 + xoffset, N*WIDTH + yoffset, '|');	
		}
		
		//绘制游戏操作方法及得分
		string strOperate = "W(UP),S(DOWN),A(LEFT),D(RIGHT),R(RESTART),N(SAVE),M(LOAD),Q(QUIT)";
		mvprintw(2*N + 3 + xoffset, N/2*WIDTH + yoffset - strOperate.length()/2, strOperate.data());

		//绘制得分及最高分
		mvprintw(N/2 + xoffset, yoffset/4, (" max:  "+to_string(max)).data());
		mvprintw(3*N/2 + xoffset, yoffset/4, ("score: "+to_string(score)).data());

		//绘制状态信息
		string strStatus;
		if (status == WIN)
			strStatus = "YOU  WIN";
		if (status == LOSE)
			strStatus = "YOU LOSE";
		mvprintw(2*N + 6 + xoffset, N/2*WIDTH + yoffset - strStatus.length()/2, strStatus.data());
		
		//初次提醒用户输入R
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

	//类初始化时游戏界面数字
	void setData() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				data[i][j] = 0;
				save[i][j] = 0;
			}
		}
	}

	//右对齐绘制数字
	void drawNum(int x, int y, int num) {
		while (num > 0){
			mvaddch(x, --y, num%10+'0');
			num = num / 10;
		}
	}

	//重新开始游戏设置
	void restart() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				data[i][j] = 0;
			}
		}

		//超出范围自动设置为1
		if (STNUM>=N*N || STNUM<0)
			randNew(1);
		else
			randNew(STNUM);
		
		score = 0;
		status = NORM;
	}

	//随机产生任意个数字
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

	//游戏左移操作
	bool moveLeft() {
		int compare[N][N];
		for (int i = 0; i < N; i++) {
			int cur = 0;         //比较值
			int pos = 0;         //存放位置

			for (int j = 0; j < N; j++) {
				compare[i][j] = data[i][j];

				//从不为0的位置开始
				if (data[i][j] == 0)
					continue;
		
				//从cur不为0开始比较求和
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

					//存放位置右移一位
					pos++;
				}

				//已经向左添加，此位置重设为0
				data[i][j] = 0;
			}

			//比较值不为0则放入
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

	//顺时针旋转90度
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

	//判断游戏是否结束
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

	//记录当前游戏记录
	void dataSave() {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				save[i][j] = data[i][j];
			}
		}
		Score = score;
	}

	//读取之前游戏记录
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


// 初始化及设置ncurses
void initialize() {
    initscr();            //初始化ncurses
    cbreak();             //设置按键直接交互
    noecho();             //设置按键不回显
    curs_set(0);          //设置光标不可见
    srand(time(NULL));    //设置随机数
}

// 恢复ncurses状态
void shutdown() {
    endwin();              //恢复终端机状态        
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

