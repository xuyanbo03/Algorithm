#include <stdio.h>
#include <stdlib.h>

/*
求两个数的最大公约数和最小公倍数

最大公约数是两个数的公共因数中最大的一个
最小公倍数是两个数的公共倍数最小的一个
*/

int gcd(int a,int b)
{
    int min;
    if(a<=0||b<=0)
        return -1;
    if(a>b)//找最小值
        min=b;
    else
        min=a;
    while (min)
    {
        if(a%min==0&&b%min==0)//判断公因数
            return min;//找到最大公因数
        min--;//没找到，自减
    }
    return -1;
}

int lcm(int a,int b)
{
    int max;
    if(a<=0||b<=0)
        return -1;
    if(a>b)//找最大值
        max=a;
    else
        max=b;
    while (max)
    {
        if(max%a==0&&max%b==0)//判断公倍数
            return max;//找到公倍数
        max++;//没找到，自增
    }
    return -1;
}

main()
{
    int a,b;
    printf("Please input two digit for getting GCD and LCM\n");
    scanf("%d %d",&a,&b);
    printf("The GCD of %d and %d is %d\n",a,b,gcd(a,b));
    printf("The LCM of %d and %d is %d\n",a,b,lcm(a,b));
    getche();
}
