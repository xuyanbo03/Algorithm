#include "stdio.h"
#include "math.h"

int mode_1(N)			/*�ж���Ȼ��N�Ƿ���Ա�ʾ��ΪN=a2����ʽ*/
{
    if((int)sqrt(N)*(int)sqrt(N)==N)
    {
      printf("%d*%d=%d\n",(int)sqrt(N),(int)sqrt(N),N);
      return 1;
    }
    else return 0;
}

int mode_2(N)			/*�ж���Ȼ��N�Ƿ���Ա�ʾ��N=a2+b2����ʽ*/
{
    int x,y;
    for(x=1;x<sqrt(N);x++)
        for(y=x;y<sqrt(N);y++)
        {
            if(x*x+y*y == N)
            {
                printf("%d^2+%d^2=%d\n",x,y,N);
                return 1;
            }

        }
    return 0;
}

int mode_3(N)			/*�ж���Ȼ��N�Ƿ���Ա�ʾ��N=a2+b2+c2����ʽ*/
{
    int x,y,z;
    for(x=1;x<sqrt(N);x++)
        for(y=x;y<sqrt(N);y++)
            for(z=y;z<sqrt(N);z++)
            {
                if(x*x+y*y+z*z == N)
                 {
                    printf("%d^2+%d^2+%d^2=%d\n",x,y,z,N);
                     return 1;
                 }
            }
    return 0;
}

int mode_4(N)			/*�ж���Ȼ��N�Ƿ���Ա�ʾ��N=a2+b2+c2+d2����ʽ*/
{
    int x,y,z,t;
    for(x=1;x<sqrt(N);x++)
        for(y=x;y<sqrt(N);y++)
            for(z=y;z<sqrt(N);z++)
                for(t=z;t<sqrt(N);t++)
                {
                     if(x*x+y*y+z*z+t*t == N)
                     {
                        printf("%d^2+%d^2+%d^2+%d^2=%d\n",x,y,z,t,N);
                        return 1;
                        }
                }
    return 0;
}

void proveFourSquares(int N)
{
    if(mode_1(N))
    printf("It has verified Four Squares");
    else if(mode_2(N))
    printf("It has verified Four Squares");
    else if(mode_3(N))
    printf("It has verified Four Squares");
    else if(mode_4(N))
    printf("It has verified Four Squares");
}

main()
{
    int N;
    printf("Please input a natural number\n");
    scanf("%d",&N);
    printf("-------- Step of Verification---------\n");
    proveFourSquares(N);
    getche();
}
