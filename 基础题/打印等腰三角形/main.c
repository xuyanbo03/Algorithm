#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PrintTrangle(int n);

/*
打印特殊图案
打印（n-1）个space
打印（2i-1）个“*”
打印1个“\n”
*/

void PrintTrangle(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n-i;j++)
            printf(" ");
        for(j=0;j<2*i-1;j++)
            printf("*");
        printf("\n");
    }
}

int main()
{
    int n;
    printf("How many rows of * for trangle\n");
    scanf("%d",&n);//等腰三角形的高度n
    PrintTrangle(n);
    getchar();
    return 0;
}
