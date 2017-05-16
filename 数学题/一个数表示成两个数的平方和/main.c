#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
找出所有满足X^2+Y^2=N的正整数对X和Y

穷举法
X、Y范围在【1，N^1/2】的正整数
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
