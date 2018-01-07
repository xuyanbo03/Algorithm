#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
�ҳ���������X^2+Y^2=N����������X��Y

��ٷ�
X��Y��Χ�ڡ�1��N^1/2����������
*/

void getXY(int N)
{
    int x,y;
    for(x=1;x<sqrt(N);x++)
    {
        for(y=x;y<sqrt(N);y++)
        {
            if(x*x+y*y==N)
            {
                printf("%d^2+%d^2=%d\n",x,y,N);
            }
        }
    }
}

main()
{
    int N;
    printf("Please input a integer N\n");
    scanf("%d",&N);
    getXY(N);
    getche();
}
