#include "stdio.h"
float Sum(int n)
{
    int i;
    float sum = 0,a=2,b=1,tmp;
    for(i=0;i<n;i++)
    {
       sum = sum +a/b;
       tmp = a + b;
       b = a;           /*��һ��ķ�ĸ����ǰһ��ķ���*/
       a = tmp;         /*��һ��ķ��ӵ���ǰһ���ĸ�����֮��*/
    }
    return sum;
}

main()
{
    printf("2+3/2+5/3+...=%f",Sum(50));
    getche();
}
