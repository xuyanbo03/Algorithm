#include "stdio.h"
int P(int n,int m)
{
    if(m==1 || n == 1) return 1;
    if(m>n) return P(n,n);
    if(m==n) return 1+P(n,m-1);
    return P(n,m-1)+P(n-m,m);
}

main()
{
    int n,s;
    printf("Please input a integer for getting the number of division\n");
    scanf("%d",&n);                    /*����������n*/
    s =    P(n,n);                    /*���������n�Ļ�����*/
    printf("The number of division of %d is %d\n",n,s);
    getche();
}

