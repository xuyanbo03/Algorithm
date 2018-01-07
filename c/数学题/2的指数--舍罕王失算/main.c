#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
舍汉王的失算

第i个是有2^(i-1)个
*/

main()
{
    double sum=0;//定义双精度变量存储大数
    int i;
    for(i=1;i<=64;i++)
        sum=sum+pow(2,i-1);//累加求和
    printf("The number of the grain is \n%f\n",sum);
}
