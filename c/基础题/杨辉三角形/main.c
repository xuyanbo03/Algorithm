#include <stdio.h>
#include <stdlib.h>

/*
打印杨辉三角形
二项式(a+b)^N的展开式的系数
第i行第j个数据的值等于第i-1行的第j-1和j个数据值之和
第i行第j个数据的值都等于1
开辟数组存放数据

6阶杨辉三角
*/

main()
{
    int i,j,k,buf[7],tmp[7];//N=6时杨辉三角形中数据为7
    for(i=0;i<=6;i++)
    {
        if(i==0)
        {
            printf("%d",1);//打印第一行
        }
        else if(i==1)
        {
            printf("\n%d %d\n",1,1);//打印第二行
            buf[0]=1;
            buf[1]=1;
        }
        else
        {
            for(j=1;j<=i+1;j++)
            {
                if(j==1||j==i+1)
                {
                    printf("%d ",1);
                    tmp[j-1]=1;
                }
                else
                {
                    printf("%d ",buf[j-2]+buf[j-1]);
                    tmp[j-1]=buf[j-2]+buf[j-1];
                }
            }
            printf("\n");
            for(k=0;k<7;k++)
                buf[k]=tmp[k];//将第i行的数据存放到buf[0]~buf[i]中
        }
    }
}
