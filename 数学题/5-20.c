#include "stdio.h"

int factorSum(a)            /*��a�����Ӻ�*/
{
    int i, sum = 0;
    for(i=1;i<a;i++)
        if(a%i == 0)            /*i��a��һ������*/
            sum = sum + i;    /*�ۼ����*/
    return sum;            /*����a�����ӵĺ�*/
}

int perfextnumber(int a)        /*�ж�a�Ƿ�����ȫ��*/
{
    if(a == factorSum(a)) return 1;
    else return 0;
}

main()
{
    int a;
    printf("There are following perfect numbers 1~1000 are:\n");
    for(a=1;a<=1000;a++)
    {                        /*Ѱ��1-1000���ڵ���ȫ��*/
        if(perfextnumber(a))
            printf("%d ",a);
    }
    getche();
}

