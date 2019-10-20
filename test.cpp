#include <iostream>
#include <sys/time.h>
#include <sys/types.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <String.h>
void swap(int &a,int &b)
{
	int t = a;
	a = b;
	b = t;
}
int getrand(int min,int max)
{
	return (min + rand() % (max - min + 1));
}
class Piece
{
public:
	int score;
	int shape;
	int next_shape;
	int head_x;
	int head_y;
	int size_h;
	int size_w;
	int next_size_h;
	int next_size_w;
	int box_shape[4][4];
	int next_box_shape[4][4];
	int box_map[30][45];
	bool game_over;
public:
	void initial();
	void set_shape(int &cshape,int box_shape[][4],int &size_w,int & size_h);
	void score_next();
	void judge();
	void move();
	void rotate();
	bool isaggin();
	bool exsqr(int row);
};
void Piece::set_shape(int &cshape,int box_shape[][4],int &size_w,int & size_h)
{
	memset(box_shape,0,sizeof(box_shape));
	switch(cshape)
	{
		case 0;
			size_h = 1;
			size_w = 4;
			shape[0][0] = 1;
			shape[0][1] = 1;
			shape[0][2] = 1;
			shape[0][3] = 1;
			break;
		case 1;
			size_h = 2;
			size_w = 3;
			shape[0][0] = 1;
			shape[1][0] = 1;
			shape[1][1] = 1;
			shape[1][2] = 1;
			break;
		case 2;
			size_h = 2;
			size_w = 3;
			shape[0][2] = 1;
			shape[1][0] = 1;
			shape[1][1] = 1;
			shape[1][2] = 1;
			break;
		case 3;
			size_h = 2;
			size_w = 3;
			shape[0][1] = 1;
			shape[0][2] = 1;
			shape[1][0] = 1;
			shape[1][1] = 1;
			break;
		case 4;
			size_h = 2;
			size_w = 3;
			shape[0][0] = 1;
			shape[0][1] = 1;
			shape[1][1] = 1;
			shape[1][2] = 1;
			break;
		case 5;
			size_h = 2;
			size_w = 2;
			shape[0][0] = 1;
			shape[1][0] = 1;
			shape[1][1] = 1;
			shape[0][1] = 1;
			break;
		case 6;
			size_h = 2;
			size_w = 3;
			shape[0][1] = 1;
			shape[1][0] = 1;
			shape[1][1] = 1;
			shape[1][2] = 1;
			break;
	}
	head_x = game_win_width/2;
	head_y = 1;
	if(isaggin())
		game_over = true;
}
void Piece