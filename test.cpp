#include <stdio.h>
#include <math.h>
int main()
{
    int m, i, j, k = 0, a[100],x;
    printf("input a number: ");
    scanf("%d", &m);
    if (m <= 0)
    {
        printf("error");
    }
    if (m >= 2)
    {
        a[k] = 2;
        k++;
        for (i = 3; i < m; i++)
        {
            x = 0;
            for (j = 2; j <= sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    x = 1;
                    break;
                }
            }
            if(x == 0 )
            {
                a[k] = i;
                k++;
            }
        }
    }
    for (i = 0; i < k; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}