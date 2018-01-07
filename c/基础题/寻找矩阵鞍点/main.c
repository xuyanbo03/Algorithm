#include <stdio.h>
#include <stdlib.h>

/*
一个矩阵中，在该行最大，在该列最小，称为鞍点。
一个矩阵也可能没有鞍点。最多出现一个鞍点。
任意输入5X5矩阵，找鞍点，并输出在矩阵的位置（行、列）

逐行寻找鞍点
先找某行最大的元素，再将此元素与同列元素比较最小
*/

int getSaddlePoint(int *x,int *y,int (*A)[5],int m,int n)
{
    int max,i,j,k,flag;
    for(i=0;i<m;i++)//逐行扫描寻找鞍点
    {
        max=0;//max记录第i行中最大值的列数
        flag=1;
        for(j=1;j<n;j++)//找出第i行中最大元素的位置A[i][max]
        {
            if(A[i][j]>A[i][max])
                max=j;
        }
        for(k=0;k<n;k++)
        {
            if(A[max]==A[i][k]&&max!=k)//本行中有与元素A[i][max]的值相等，没有鞍点
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            for(k=0;k<m;k++)//判断A[i][max]是否是本列中最小的
            {
                if(A[k][max]<=A[i][max]&&k!=i)//不是最小元素，不是鞍点
                {
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1)//找到鞍点，用*x,*y返回，程序结束
        {
            *x=i;//行
            *y=max;//列
            return 1;
        }
    }
    return 0;//没有找到鞍点
}

main()
{
    int A[5][5],i,j,x,y;
    printf("Please input some digit into the 5X5 matrix\n");
    for(i=0;i<5;i++)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&A[i][j]);//输入矩阵
        }
    }
    if(getSaddlePoint(&x,&y,A,5,5))
    {
        printf("\nSaddlePoint is at (%d,%d)",x+1,y+1);
    }
    else
    {
        printf("\nThere is no in the matrix\n");
    }
    getchar();
}
