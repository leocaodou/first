#include <stdio.h>
int main()
{
	int n,ax,ay,bx,by,cx,cy;
	scanf("%d",&n);
	scanf("%d%d",&ax,&ay);
	scanf("%d%d",&bx,&by);
	scanf("%d%d",&cx,&cy);
	if((bx>=ax&&cx<=ax)||(by>=ay&&cy<=ay)||(bx<=ax&&cx>=ax)||(by<=ay&&cy>=ay))
		printf("NO");
	else
		printf("YES");
	return 0;
}