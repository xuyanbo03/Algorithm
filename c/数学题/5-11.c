#include"stdio.h"
main()
{
    int sum = 1,i;   /*sum ��ʼֵΪ1����ʾ��ʮ���������*/
    for(i=9;i>=1;i--)
         sum = (sum + 1) * 2 ;  /*ÿ��ѭ�����ó���i���������*/
    printf("The number of peach are %d\n",sum);
    getche();
}

