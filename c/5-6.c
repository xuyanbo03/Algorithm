/*************  Procedure isCircle *******************/
#include <string.h> 
#include <stdio.h> 

int isCircle(int n);/*�ж�n�Ƿ��ǻ�������*/
int reverse(int i); /*����i �ĵ�����*/

void main()
{
    int n;
    printf("Type a integer for judging is Circle:\n");
    scanf("%d",&n);                            /*����Ļ����һ����*/
    if(isCircle(n))                              /*�ж��ǻ�������*/
        printf("%d is Circle\n",n);
    else
        printf("%d is not Circle\n",n);          /*�жϲ��ǻ�������*/
    getchar();
}

int isCircle(int n)
{  /*����isCircle �ж�n�Ƿ��ǻ�������*/
    int m;
    m= reverse(n);
    if(m==n)
        return 1;
    else
        return 0;
}

int reverse(int i)
{   /*��i �ĵ�����*/
    int m,j=0;
    m=i;
    while(m){
      j=j*10+m%10;
      m=m/10;
    }
    return j;   /*����i�ĵ�����j*/
}

