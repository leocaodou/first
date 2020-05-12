#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <queue>
#include <ctime>
#define Black -1
#define White 1
#define Denpth 5
#define Infinite 10000000
using namespace std;
long long HashValue[15][15][2];
class Ha
{
public:
	int val = 0;
	int denpth = 0;
};
Ha Hash[100000000];
void SetHashValue()
{
	for(int i = 0;i < 15;i++)
		for(int j = 0;j < 15;j++)
			for(int k = 0;k < 2;k++)
				HashValue[i][j][k] = rand()%9223372036854775807;
}
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
	void add2(int x,int y,int who)
	{
		bord[x][y] = who;
		lastx = x;
		lasty = y;
		last = who;
	}
	void DeleteP(int x,int y)
	{
		bord[x][y] = 0;
	}
	bool empty(int a,int b)
	{
		if(bord[a][b] == 0)
			return true;
		else
			return false;
	}
};
bool Search(table& T,int& v,int denpth)
{
	long long sum = 0;
	for(int i = 0;i < 15;i++)
		for(int j = 0;j < 15;j++)
		{
			if(T.bord[i][j] == -1)
				sum = (sum + HashValue[i][j][0]) % 100000000;
			else if(T.bord[i][j] == 1)
				sum = (sum + HashValue[i][j][1]) % 100000000;
		}
	if(Hash[sum].val != 0 && Hash[sum].denpth >= Denpth - denpth)
	{
		v = Hash[sum].val - 100000;
		Hash[sum].denpth = denpth;
		return true;
	}
	else
		return false;
}
void Store(table& T,int v,int denpth)
{
	long long sum = 0;
	for(int i = 0;i < 15;i++)
		for(int j = 0;j < 15;j++)
		{
			if(T.bord[i][j] == -1)
				sum = (sum + HashValue[i][j][0]) % 100000000;
			else if(T.bord[i][j] == 1)
				sum = (sum + HashValue[i][j][1]) % 100000000;
		}
	Hash[sum].val = v + 100000;
	Hash[sum].denpth = denpth;
	return;
}
int f(table& T,int Who)
{
	void show(table x);
	int sum = 0;
	for(int i = 0; i < 15;i++)
	{
		for(int j = 0; j <= 9;j++)
		{
			int w = 1;
			int p = 0, q = 0;
			for(int k = j;k < j + 6;k++)
			{
				if(T.bord[i][k] == Who)
					p++;
				else if(T.bord[i][k] == -Who)
					q++;
			}
			if(p == 0)
				continue;
			if(q == 0)
			{
				switch(p)
				{
					case 4:
						if(T.bord[i][j] != Who && T.bord[i][j+5] != Who)
						{
							sum += 4320;
							w = 0;
						}
						break;
					case 3:
						if(T.bord[i][j] != Who && T.bord[i][j+5] != Who)
						{
							sum += 720;
							w = 0;
						}
						break;
					case 2:
						if(T.bord[i][j] != Who && T.bord[i][j+5] != Who)
						{
							sum += 120;
							w = 0;
						}
						break;
					case 1:
						if(T.bord[i][j+3] == Who || T.bord[i][j+2] == Who)
						{
							sum += 20;
							w = 0;
						}
						break;
				}
			}
			if(w == 0)
				continue;
			for(int l = 0;l < 2;l++)
			{
				p = 0;
				q = 0;
				for(int k = j + l;k < j + l + 5;k++)
				{
					if(T.bord[i][k] == Who)
						p++;
					else if(T.bord[i][k] == -Who)
						q++;
				}
				if(p == 0)
					continue;
				if(q == 0)
				{
					switch(p)
					{
						case 5:
							sum += 50000;
							w = 0;
							break;
						case 4:
							sum += 720;
							w = 0;
							break;
					}
				}
			}
		}
	}
//	cout << sum <<endl;
	for(int i = 0; i < 15;i++)
	{
		for(int j = 0; j <= 9;j++)
		{
			int w = 1;
			int p = 0, q = 0;
			for(int k = j;k < j + 6;k++)
			{
				if(T.bord[k][i] == Who)
					p++;
				else if(T.bord[k][i] == -Who)
					q++;
			}
			if(p == 0)
				continue;
			if(q == 0)
			{
				switch(p)
				{
					case 4:
						if(T.bord[j][i] != Who && T.bord[j+5][i] != Who)
						{
							sum += 4320;
							w = 0;
						}
						break;
					case 3:
						if(T.bord[j][i] != Who && T.bord[j+5][i] != Who)
						{
							sum += 720;
							w = 0;
						}
						break;
					case 2:
						if(T.bord[j][i] != Who && T.bord[j+5][i] != Who)
						{
							sum += 120;
							w = 0;
						}
						break;
					case 1:
						if(T.bord[j+3][i] == Who ||T.bord[j+2][i] == Who)
						{
							sum += 20;
							w = 0;
						}
						break;
				}
			}
			if(w == 0)
				continue;
			for(int l = 0;l < 2;l++)
			{
				p = 0;
				q = 0;
				for(int k = j + l;k < j + l + 5;k++)
				{
					if(T.bord[k][i] == Who)
						p++;
					else if(T.bord[k][i] == -Who)
						q++;
				}
				if(p == 0)
					continue;
				if(q == 0)
				{
					switch(p)
					{
						case 5:
							sum += 50000;
							w = 0;
							break;
						case 4:
							sum += 720;
							w = 0;
							break;
					}
				}
			}
		}
	}
//	cout << sum <<endl;
	for(int i = 0; i < 19;i++)
	{
		if(i < 10)
		{
			for(int j = 0; j <= i;j++)
			{
				int w = 1;
				int p = 0, q = 0;
				for(int k = 0;k < 6;k++)
				{
					if(T.bord[i+5-j-k][j+k] == Who)
						p++;
					else if(T.bord[i+5-j-k][j+k] == -Who)
						q++;
				}
				if(p == 0)
					continue;
				if(q == 0)
				{
					switch(p)
					{
						case 4:
							if(T.bord[i+5-j][j] != Who && T.bord[i-j][j+5] != Who)
							{
								sum += 4320;
								w = 0;
							}
							break;
						case 3:
							if(T.bord[i+5-j][j] != Who && T.bord[i-j][j+5] != Who)
							{
								sum += 720;
								w = 0;
							}
							break;
						case 2:
							if(T.bord[i+5-j][j] != Who && T.bord[i-j][j+5] != Who)
							{
								sum += 120;
								w = 0;
							}
							break;
						case 1:
							if(T.bord[i+2-j][j+3] == Who || T.bord[i+3-j][j+2] == Who)
							{
								sum += 20;
								w = 0;
							}
							break;
					}
				}
				if(w == 0)
					continue;
				for(int l = 0;l < 2;l++)
				{
					p = 0;
					q = 0;
					for(int k = l;k < l + 5;k++)
					{
						if(T.bord[i+5-j-k][j+k] == Who)
							p++;
						else if(T.bord[i+5-j-k][j+k] == -Who)
							q++;
					}
					if(p == 0)
						continue;
					if(q == 0)
					{
						switch(p)
						{
							case 5:
								sum += 50000;
								w = 0;
								break;
							case 4:
								sum += 720;
								w = 0;
								break;
						}
					}
				}
			}
		}
		else
		{
			for(int j = 0; j <= 18-i;j++)
			{
				int w = 1;
				int p = 0, q = 0;
				for(int k = 0;k < 6;k++)
				{
					if(T.bord[14-k-j][i-9+k+j] == Who)
						p++;
					else if(T.bord[14-k-j][i-9+k+j] == -Who)
						q++;
				}
				if(p == 0)
					continue;
				if(q == 0)
				{
					switch(p)
					{
						case 4:
							if(T.bord[14-j][i-9+j] != Who && T.bord[9-j][i-4+j] != Who)
							{
								sum += 4320;
								w = 0;
							}
							break;
						case 3:
							if(T.bord[14-j][i-9+j] != Who && T.bord[9-j][i-4+j] != Who)
							{
								sum += 720;
								w = 0;
							}
							break;
						case 2:
							if(T.bord[14-j][i-9+j] != Who && T.bord[9-j][i-4+j] != Who)
							{
								sum += 120;
								w = 0;
							}
							break;
						case 1:
							if(T.bord[12-j][i-7+j] == Who || T.bord[11-j][i-6+j] == Who)
							{
								sum += 20;
								w = 0;
							}
							break;
					}
				}
				if(w == 0)
					continue;
				for(int l = 0;l < 2;l++)
				{
					p = 0;
					q = 0;
					for(int k = j + l;k < j + l + 5;k++)
					{
						if(T.bord[14 - k][i-9+k] == Who)
							p++;
						else if(T.bord[14 - k][i-9+k] == -Who)
							q++;
					}
					if(p == 0)
						continue;
					if(q == 0)
					{
						switch(p)
						{
							case 5:
								sum += 50000;
								w = 0;
								break;
							case 4:
								sum += 720;
								w = 0;
								break;
						}
					}
				}
			}
		}
	}
//	cout << sum <<endl;
	for(int i = 0; i < 19;i++)
	{
		if(i < 10)
		{
			for(int j = 0; j <= i;j++)
			{
				int w = 1;
				int p = 0, q = 0;
				for(int k = j;k < j + 6;k++)
				{
					if(T.bord[i+5-k][14-k] == Who)
						p++;
					else if(T.bord[i+5-k][14-k] == -Who)
						q++;
				}
				if(p == 0)
					continue;
				if(q == 0)
				{
					switch(p)
					{
						case 4:
							if(T.bord[i+5-j][14-j] != Who && T.bord[i-j][9-j] != Who)
							{
								sum += 4320;
								w = 0;
							}
							break;
						case 3:
							if(T.bord[i+5-j][14-j] != Who && T.bord[i-j][9-j] != Who)
							{
								sum += 720;
								w = 0;
							}
							break;
						case 2:
							if(T.bord[i+5-j][14-j] != Who && T.bord[i-j][9-j] != Who)
							{
								sum += 120;
								w = 0;
							}
							break;
						case 1:
							if(T.bord[i+3-j][12-j] == Who || T.bord[i+2-j][11-j] == Who)
							{
								sum += 20;
								w = 0;
							}
							break;
					}
				}
				if(w == 0)
					continue;
				for(int l = 0;l < 2;l++)
				{
					p = 0;
					q = 0;
					for(int k = j + l;k < j + l + 5;k++)
					{
						if(T.bord[i+5-k][14-k] == Who)
							p++;
						else if(T.bord[i+5-k][14-k] == -Who)
							q++;
					}
					if(p == 0)
						continue;
					if(q == 0)
					{
						switch(p)
						{
							case 5:
								sum += 50000;
								w = 0;
								break;
							case 4:
								sum += 720;
								w = 0;
								break;
						}
					}
				}
			}
		}
		else
		{
			for(int j = 0; j <= 18-i;j++)
			{
				int w = 1;
				int p = 0, q = 0;
				for(int k = j;k < j + 6;k++)
				{
					if(T.bord[14 - k][23-i-k] == Who)
						p++;
					else if(T.bord[14 - k][23-i-k] == -Who)
						q++;
				}
				if(p == 0)
					continue;
				if(q == 0)
				{
					switch(p)
					{
						case 4:
							if(T.bord[14-j][23-i-j] != Who && T.bord[9-j][18-i-j] != Who)
							{
								sum += 4320;
								w = 0;
							}
							break;
						case 3:
							if(T.bord[14-j][23-i-j] != Who && T.bord[9-j][18-i-j] != Who)
							{
								sum += 720;
								w = 0;
							}
							break;
						case 2:
							if(T.bord[14-j][23-i-j] != Who && T.bord[9-j][18-i-j] != Who)
							{
								sum += 120;
								w = 0;
							}
							break;
						case 1:
							if(T.bord[12-j][21-i-j] == Who || T.bord[11-j][20-i-j] == Who)
							{
								sum += 20;
								w = 0;
							}
							break;
					}
				}
				if(w == 0)
					continue;
				for(int l = 0;l < 2;l++)
				{
					p = 0;
					q = 0;
					for(int k = j + l;k < j + l + 5;k++)
					{
						if(T.bord[14 - k][14-i+9-k] == Who)
							p++;
						else if(T.bord[14 - k][14-i+9-k] == -Who)
							q++;
					}
					if(p == 0)
						continue;
					if(q == 0)
					{
						switch(p)
						{
							case 5:
								sum += 50000;
								w = 0;
								break;
							case 4:
								sum += 720;
								w = 0;
								break;
						}
					}
				}
			}
		}
	}
//	cout << sum <<endl;
	int p = 0, q = 0;
	for(int i = 0;i < 5;i++)
	{
		if(T.bord[4-i][i] == Who)
			p++;
		else if(T.bord[4-i][i] == -Who)
			q++;
		if(q != 0||p == 0)
			break;
		if(p == 5)
			sum += 50000;
		else if(p == 4)
			sum += 720;
	}
	p = 0;
	q = 0;
	for(int i = 0;i < 5;i++)
	{
		if(T.bord[14-i][10 + i] == Who)
			p++;
		else if(T.bord[14-i][10 + i] == -Who)
			q++;
		if(q != 0||p == 0)
			break;
		if(p == 5)
			sum += 50000;
		else if(p == 4)
			sum += 720;
	}
	p = 0;
	q = 0;
	for(int i = 0;i < 5;i++)
	{
		if(T.bord[4-i][14-i] == Who)
			p++;
		else if(T.bord[4-i][14-i] == -Who)
			q++;
		if(q != 0||p == 0)
			break;
		if(p == 5)
			sum += 50000;
		else if(p == 4)
			sum += 720;
	}
	p = 0;
	q = 0;
	for(int i = 0;i < 5;i++)
	{
		if(T.bord[4-i][i] == Who)
			p++;
		else if(T.bord[4-i][i] == -Who)
			q++;
		if(q != 0||p == 0)
			break;
		if(p == 5)
			sum += 50000;
		else if(p == 4)
			sum += 720;
	}
//	show(T);
//	system("cls");
	return sum;
}
void people(table &T)
{
	printf("请输入您要下棋的坐标\n");
	int x,y;
	scanf("%d",&x);
	scanf("%d",&y);
	Position p(x,y);
	T.add(p,White);
}
int MaxMin(int who,int denpth,table T,int alpha,int beta)
{
	bool Gameover(table T);
	void show(table x);
	int i = T.lastx - 4;
	int j = T.lasty - 4;
	int k = 0,l = 0;
	if(denpth == Denpth)
	{
//		show(T);
//		system("cls");
		return f(T,Black) - f(T,White);
	}
	else
	{
		if(who == White)
		{
			int max = -Infinite;
			while(1)
			{
				if(i+l >= 0 && i+l < 15 && j + k >= 0 && j + k < 15 && T.empty(i+l,j + k))
				{
					T.add2(i+l,j + k,White);
					int v;
					if(!Gameover(T))
					{
						if(!Search(T,v,denpth))
						{
							v = MaxMin(Black,denpth + 1,T,alpha,beta);
							Store(T,v,denpth);
						}
					}
					else
						v = -Infinite;
					if(max < v)
					{
						max = v;
					}
					T.DeleteP(i+l,j+k);
					if(alpha < v)
					{
						alpha = v;
					}
					if(alpha >= beta)
						return Infinite;
				}
				k++;
				if(k == 9)
				{
					l++;
					k = 0;
				}
				if(l == 9 || i+l >= 15)
					break;
			}
			return max;
		}
		else
		{
			int min = Infinite;
			while(1)
			{
				if(i+l >= 0 && i+l < 15 && j + k >= 0 && j + k < 15 && T.empty(i+l,j + k))
				{
					T.add2(i+l,j + k,Black);
					int v;
					if(!Gameover(T))
					{
						if(!Search(T,v,denpth))
						{
							v = MaxMin(White,denpth + 1,T,alpha,beta);
							Store(T,v,denpth);
						}
					}
					else v = Infinite;
					if(min > v)
					{
						min = v;
					}
					T.DeleteP(i+l,j+k);
					if(beta > v)
					{
						beta = v;
					}
					if(alpha >= beta)
						return -Infinite;
				}
				k++;
				if(k == 9)
				{
					l++;
					k = 0;
				}
				if(l == 9 || i+l >= 15)
					break;
			}
			return min;
		}
	}
}
bool Gameover(table T)
{
	int x = T.lastx;
	int y = T.lasty;
	int who = T.last;
	int u=0,d=0,l=0,r=0,lu=0,ld=0,ru=0,rd=0;
	int i = 1;
	while(x + i  <= 14 && T.bord[x+i][y] == who)
	{
		d++;
		i++; 
	}
	i = 1;
	while(x + i  <= 14 && y + i  <= 14 && T.bord[x+i][y+i] == who)
	{
		rd++;
		i++;	
	}
	i = 1;
	while(x + i  <= 14 && T.bord[x+i][y-i] == who)
	{
		ld++;
		i++;	
	}
	i = 1;
	while(x - i  >= 0 && T.bord[x-i][y] == who)
	{
		u++;
		i++;
	}
	i = 1;
	while(x - i  >= 0 && y + i  <= 14 && T.bord[x-i][y+i] == who)
	{
		ru++;
		i++;
	}
	i = 1;
	while(x - i  >= 0 && y - i  >= 0 && T.bord[x-i][y-i] == who)
	{
		lu++;
		i++;
	}
	i = 1;
	while( y - i  >= 0 && T.bord[x][y-i] == who)
	{
		l++;
		i++;
	}
	i = 1;
	while(y + i  <= 14 && T.bord[x][y+i] == who)
	{
		r++;
		i++;
	}
	if((u+d+1>=5) ||(l+r+1>=5) || (lu+rd+1>=5) || (ru+ld+1>=5))
		return true;
	else
		return false;
}
void DouAi(table& T,int denpth)
{
	int i = T.lastx - 4;
	int j = T.lasty - 4;
	int k = 0,l = 0;
	int x = -1,y = -1,max = -Infinite;
	while(1)
	{
		if(i+l >= 0 && i+l < 15 && j + k >= 0 && j + k < 15 && T.empty(i+l,j + k))
		{
			T.add2(i+l,j+k,Black);
			int v;
			int alpha = -Infinite;
			int beta = Infinite;
			if(!Search(T,v,denpth))
			{
				v = MaxMin(White,denpth + 1,T,alpha,beta);
				Store(T,v,denpth);
			}
			cout << i+l+1 << ' '<< j+k+1 << ' ' << v << endl;
			if(max < v)
			{
				max = v;
				x = i + l;
				y = j + k;
			}
			T.DeleteP(i+l,j+k);
		}
		k++;
		if(k == 9)
		{
			l++;
			k = 0;
		}
		if(l == 9 || i+l >= 15)
			break;
	}
	T.add2(x,y,Black);
}
void show(table x)
{
	cout << "   ";
	for(int i=0;i < 9;i++)
		cout << i + 1 << "   ";
	for(int i=9;i < 15;i++)
		cout << i + 1 << "  ";
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
				printf("○──");
			else if(x.bord[i][j] == 1)
				printf("●──");
			else
			{ 
				if(i == 0)
				{
					if(j == 0)
						printf("┌───");
					else if(j == 14)
						printf("┐");
					else
						printf("┬───");

				}
				else if(i == 14)
				{
					if(j == 0)
						printf("└───");
					else if(j == 14)
						printf("┘");
					else
						printf("┴───");
				}
				else
				{
					if(j == 0)
						printf("├───");
					else if(j == 14)
						printf("┤");
					else
						printf("┼───");
				}
			}
		}
		printf("\n   ");
		if(i != 14)
		{
			for(int j = 0;j < 15;j++)
				printf("│   ");
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
		if(Gameover(T))
		{
			printf("你赢了");
			break;
		}
		printf("请稍等\n");
		DouAi(T,0);
//		system("cls");
		show(T);
		if(Gameover(T))
		{
			printf("你输了");
			break;
		}
	} 
}
int main()
{
	SetHashValue();
	GameStart();
}
