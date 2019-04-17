#include <stdio.h>
int main()
{
    int m,a[100],t,i=0,n=0,c,b,g=0;
    printf("Input:\nPlease input a number:\n");
    scanf("%d",&m);
    printf("Output:\n");
    if(m<=0)
    {
        printf("error!\n");
    }
    else if(m>0)
    {
    	for(t=1;t<=m;t++)
    	{
    		g=0;
        	for(c=1;c<=t;c++)
        	{
        		if(t%c==0)
        		  g++;
        	}
        	if(g==2)
        	{
    			a[n]=t;
    			n++;
            }
    	}
    	if(n>100)
       		printf("overflow!");
    	else
			for(i=0;i<n;i++)
			{
                printf("%5d",a[i]);
                if(i==0)
                    continue;
				if(i%15==0)
                    printf("\n");
			}
    }
	return 0;
}
