#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<math.h>
using namespace std;
int button=0,maxn=0;//游戏开始
int square[6][6];//游戏格子
int aa[6],bb[6];
int score=0,sco=0;
void outt_little(){
	int i,a=0,b=0,c=0,d=0;
	printf("╔════╦════╦════╦════╗\n");
		{i=1;a=square[i][1]; b=square[i][2]; c=square[i][3]; d=square[i][4];}
	printf("║%4d║%4d║%4d║%4d║\n",a,b,c,d);
	printf("╠════╬════╬════╬════╣\n");
		{i=2;a=square[i][1]; b=square[i][2]; c=square[i][3]; d=square[i][4];}
	printf("║%4d║%4d║%4d║%4d║\n",a,b,c,d);
	printf("╠════╬════╬════╬════╣\n");	
		{i=3;a=square[i][1]; b=square[i][2]; c=square[i][3]; d=square[i][4];}
	printf("║%4d║%4d║%4d║%4d║\n",a,b,c,d);
	printf("╠════╬════╬════╬════╣\n");
		{i=4;a=square[i][1]; b=square[i][2]; c=square[i][3]; d=square[i][4];}
	printf("║%4d║%4d║%4d║%4d║\n",a,b,c,d);
	printf("╚════╩════╩════╩════╝\n");
}
 
void outt_mid(){
	int i,j,a,b,c,d;
	char str[10];
	sprintf(str,"%d",a);		
	printf("╔══════╦══════╦══════╦══════╗\n");
	printf("║      ║      ║      ║      ║\n");
	j=1;
	for(int i=1;i<=3;i++)	
		if(square[j][i]==0)  printf("║      "); 
						else printf("║%5d ",square[j][i]);
	if(square[j][4]==0) printf("║      ║\n");
						else printf("║%5d ║\n",square[j][4]);
	printf("╠══════╬══════╬══════╬══════╣\n");
	printf("║      ║      ║      ║      ║\n");
	j=2;
	for(int i=1;i<=3;i++)	
		if(square[j][i]==0)  printf("║      "); 
						else printf("║%5d ",square[j][i]);
	if(square[j][4]==0) printf("║      ║\n");
						else printf("║%5d ║\n",square[j][4]);
	printf("╠══════╬══════╬══════╬══════╣\n");
	printf("║      ║      ║      ║      ║\n");
	j=3;
	for(int i=1;i<=3;i++)	
		if(square[j][i]==0)  printf("║      "); 
						else printf("║%5d ",square[j][i]);
	if(square[j][4]==0) printf("║      ║\n");
						else printf("║%5d ║\n",square[j][4]);
	printf("╠══════╬══════╬══════╬══════╣\n");
	printf("║      ║      ║      ║      ║\n");
	j=4;
	for(int i=1;i<=3;i++)	
		if(square[j][i]==0)  printf("║      "); 
						else printf("║%5d ",square[j][i]);
	if(square[j][4]==0) printf("║      ║\n");
						else printf("║%5d ║\n",square[j][4]);
	printf("╚══════╩══════╩══════╩══════╝\n");
 
}
 
void intt(){
	int n,m,numb;
	memset(square,0,sizeof(square));
	srand(time(NULL));
	n = rand() % 3 + 1;
	m = rand() % 3 + 1;
	while(square[n][m]!=0)
	{
		n = rand() % 4 + 1;
		m = rand() % 4 + 1;
	}
	numb=rand() % 2 + 1;
	button++;
	square[n][m]=numb;
}
 
void add_num(){
	int n,m,numb;
	n = rand() % 3 + 1;
	m = rand() % 3 + 1;
	while(square[n][m]!=0)
	{
		n = rand() % 4 + 1;
		m = rand() % 4 + 1;
	}
	numb=rand() % 2 + 1;
	square[n][m]=numb;
	button++;
}
char check(){
	int ch;
	while( (ch=getch())!=0x1B ) /* Press ESC to quit... */
    {
      switch(ch)
      {
      case 0xE0:
         switch(ch=getch())
         {
            case 72:  return('u');break;
            case 80:  return('d');break;
            case 75:  return('l');break;
            case 77:  return('r');break;
            default:
               break;
         }
         break;
      default:
         break;
      }
   }
}
 
void run(char x){
	int count1,count;//sco分数； 
	sco=0;
	memset(aa,0,sizeof(aa));
	memset(bb,0,sizeof(bb));
	if(x=='l'||x=='r')
	for(int i=1;i<=4;i++)
	{
		count1=0;
		for(int j=1;j<=4;j++) 
			if (square[i][j]!=0) 
			{
				count1++;
				aa[count1]=square[i][j];
			}
			
		int l=1;
		int r=1;
		count=0;
		while(l<=count1)
		{
			if (aa[r]==aa[r+1]) r++;
			count++;
			bb[count]=(r-l+1)*aa[l];
			maxn=max(maxn,bb[count]);
			if(r>l) sco=sco+bb[count];
			l=r+1;
			r++;
		}
		for(int j=1;j<=4;j++)
			square[i][j]=0;
		if (x=='l') 
			for(int j=1;j<=count;j++)
				square[i][j]=bb[j];
		if (x=='r') 
			for(int j=1;j<=count;j++)
				square[i][4-j+1]=bb[count-j+1];	
		button=button-count1+count;			
	}
	if(x=='u'||x=='d')
	for(int i=1;i<=4;i++)
	{
		count1=0;
		for(int j=1;j<=4;j++) 
			if (square[j][i]!=0) 
			{
				count1++;
				aa[count1]=square[j][i];
			}
			
		int l=1;
		int r=1;
		count=0;
		while(l<=count1)
		{
			if (aa[r]==aa[r+1]) r++;
			count++;
			bb[count]=(r-l+1)*aa[l];
			maxn=max(maxn,bb[count]);
			if(r>l) sco+=bb[count];
			l=r+1;
			r++;
		}
		for(int j=1;j<=4;j++)
			square[j][i]=0;
		if (x=='u') 
			for(int j=1;j<=count;j++)
				square[j][i]=bb[j];
		if (x=='d') 
			for(int j=1;j<=count;j++)
				square[4-j+1][i]=bb[count-j+1];	
		button=button-count1+count;		
	}
	score=sco+score;
	
} 
 
bool check_fail(){
	for(int i=1;i<=4;i++)
		for(int j=1;j<=3;j++)
			if (square[i][j]==square[i][j+1]) return true;
	for(int i=1;i<=4;i++)
		for(int j=1;j<=3;j++)
			if (square[j][i]==square[j+1][i]) return true;
	return(false);
}
 
int main(){
	system("mode con cols=30 lines=16");
	system("COLOR 73");
	intt();
	while (button<=16)
	{
		if (button==16)
			if(!(check_fail())) break;
		outt_mid();//输出 
		cout<<"max = "<<maxn<<endl;
		cout<<"score = "<<score<<endl;
		if(maxn>=2048) cout<<"Congratulations! You are win!"<<endl;
		char ch=check();//读入方向键 
		
		switch(ch){
			case 'l':run('l');break;
			case 'r':run('r');break;
			case 'd':run('d');break;
			case 'u':run('u');break;
		}
		if(button<16) add_num();
		system("cls");//清除
	}
	
	if (button==16) {
		outt_mid();
		cout<<"Sorry!You are failed."<<endl;
	}
	while(1);
	return 0;
}
