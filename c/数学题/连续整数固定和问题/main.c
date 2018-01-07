#include <stdio.h>
#include <stdlib.h>

/*
连续整数固定和问题

穷举法
小于n的子串累加，子串可能发生重叠
穷举搜索：采用固定起点，扫描数列元素的方法进行连续整数固定和的搜索
*/

void cntnsIntSum(int n)
{
    int i,sum=0,j;
    for(i=1;i<n;i++)//控制起点的选择，从1到n-1
    {
        j=i-1;
        while(sum<n)//从起点向后顺序累加
        {
            j++;//连续累加到的整数
            sum=sum+j;//求和
        }
        if(sum==n)
        {
            printf("%d+...+%d=%d\n",i,j,n);
        }
        sum=0;
    }
}

main()
{
    int n;
    printf("Please input a integer\n");
    scanf("%d",&n);
    cntnsIntSum(n);
    getche();
}
