#include "stdio.h"

int factorSum(a)                /*��a�����Ӻ�*/
{
    int i, sum = 0;
    for(i=1;i<a;i++)            
        if(a%i == 0)                /*i��a��һ������*/
            sum = sum + i;        /*ͨ������sum�ۼ����*/
    return sum;                    /*����a�����ӵĺ�*/
}

int isfriend(int a,int b,int i,int j)        /*�ж�a,b�Ƿ�����������������������1�����򷵻�0*/
{
    if(a==j && b== i )return 1;
    else return 0;
}

friendly()                        /*Ѱ��1-3000��Χ�ڵ�������*/
{
  int i , j, x[3001];
  for(i=1;i<=3000;i++)
    x[i] = factorSum(i);
  for(i=1;i<=3000;i++)
  {
    if(x[i]!=-111){
        for(j=i+1;j<=3000;j++)
            if(isfriend(x[i],x[j],i,j))
            {
                printf("(%d,%d) ",i,j);
                x[j] = -111;                ��*��ʾj�Ѿ��ҵ�������*/
            }
    }
  }
}

main()
{
    printf("There are following friendly numbers from 1 to 3000\n");
    friendly();
    getche();
}

