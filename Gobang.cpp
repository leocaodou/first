#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
#include <ctime>
#define Black -1;
#define White 1;
#define Denpth 5;
using namespace std;
class Position
{
public:
	int x;
	int y;
	Position(int a,int b):x(a),y(b){}
};
class table
{
public:
	int lastx = 0;
	int lasty = 0;
	int last;
	int bord[15][15] =
	{
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	int value;
	void add(Position p,int who)
	{
		bord[p.x-1][p.y-1] = who;
		lastx = p.x - 1;
		lasty = p.y - 1;
		last = who;
	}
};
class Value
{
public:
	int x;
	int y;
};
void people(table &T)
{
	printf("请输入你下棋位置的坐标");
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	Position p(x,y);
	T.add(p,1);
}
bool Gameover(table T)
{
	int x = T.lastx;
	int y = T.lasty;
	int who = T.last;
	int u=0,d=0,l=0,r=0,lu=0,ld=0,ru=0,rd=0;
	int i = 1;
	while(x + i  < 14 && T.bord[x+i][y] == who)
	{
		if(T.bord[x+i][y] == who)
			d++;
		i++; 
	}
	i = 1;
	while(x + i  < 14 && T.bord[x+i][y+i] == who)
	{
		if(y + i < 14 && T.bord[x+i][y+i] == who)
			rd++;
		i++;	
	}
	i = 1;
	while(x + i  < 14 && T.bord[x+i][y-i] == who)
	{
		if(y + i < 14 && T.bord[x+i][y-i] == who)
			ld++;	
	}
	i = 1;
	while(x - i  >= 0 && T.bord[x-i][y] == who)
	{
		if(T.bord[x-i][y] == who)
			u++;
		i++;
	}
	i = 1;
	while(x - i  >= 0 && T.bord[x-i][y+i] == who)
	{
		if(T.bord[x-i][y+i] == who)
			ru++;
		i++;
	}
	i = 1;
	while(x - i  >= 0 && T.bord[x-i][y-i] == who)
	{
		if(y - i < 14 && T.bord[x-i][y-i] == who)
			lu++;
		i++;
	}
	if((u+d+1>=5) ||(l+r+1>=5) || (lu+rd+1>=5) || (ru+ld+1>=5))
		return true;
	else
		return false;
}
void show(table x)
{
	cout << "   ";
	for(int i=0;i < 9;i++)
		cout << i + 1 << "  ";
	for(int i=9;i < 15;i++)
		cout << i + 1 << " ";
	cout << endl;
	for(int i=0;i < 15;i++)
	{
		if(i + 1 < 10)
			cout << i + 1 << "  ";
		else
			cout << i + 1 << ' ';
		for(int j=0;j < 15;j++)
		{
			if(x.bord[i][j] == -1)

				printf("●─");
			else if(x.bord[i][j] == 1)
				printf("○─");
			else
			{ 
				if(i == 0)
				{
					if(j == 0)
						printf("┌──");
					else if(j == 14)
						printf("┐");
					else
						printf("┬──");

				}
				else if(i == 14)
				{
					if(j == 0)
						printf("└──");
					else if(j == 14)
						printf("┘");
					else
						printf("┴──");
				}
				else
				{
					if(j == 0)
						printf("├──");
					else if(j == 14)
						printf("┤");
					else
						printf("┼──");
				}
			}
		}
		printf("\n   ");
		if(i != 14)
		{
			for(int j = 0;j < 15;j++)
				printf("│  ");
			printf("\n");
		}
	}
	printf("\n");
}
void GameStart()
{
	srand(int(time(0)));
	table T;
	int x = rand()%25 + 1;
	Position f((4+x/5),(4+x%5));
	T.add(f,-1);
	show(T);
	while(1)
	{
		people(T);
		system("cls");
		show(T);
		printf("请稍等");
		int a;
		cin >> a;
		//DouAi(T);
	} 
}
int main()
{
	GameStart();
}
