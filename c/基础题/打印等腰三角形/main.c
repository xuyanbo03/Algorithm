#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PrintTrangle(int n);

/*
��ӡ����ͼ��
��ӡ��n-1����space
��ӡ��2i-1������*��
��ӡ1����\n��
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
    scanf("%d",&n);//���������εĸ߶�n
    PrintTrangle(n);
    getchar();
    return 0;
}
