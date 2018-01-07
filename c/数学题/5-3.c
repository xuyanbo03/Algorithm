/***********************Procedure Goldbach Guess*******************************/
#include <string.h> 
#include <stdio.h> 

int isGoldbach(int a);
int TestifyGB_Guess(int low,int high);
int isPrime(int i);
void main()
{
    /*��֤1~100���ڵĸ�°ͺղ���*/
    printf("Now testify Goldbach Guess in the range of 1~100\n\n");
    if(TestifyGB_Guess(1,100))
        printf("\nIn the range of 1~100,Goldbach Guess is right.\n");
    else  printf("\nGoldbach Guess is wrong.\n");
    getchar();
}
 
int TestifyGB_Guess (int low,int high)
{/*��low��high�ķ�Χ����֤��°ͺղ���*/
    int i,j=0;
    int flag=0;
    for(i=low;i<=high;i++)
        if(i%2==0&&i>2)
            if(isGoldbach(i)){           /*ż��i���ϸ�°ͺղ���*/
            j++;                         /*j�������������ʽ*/
            if(j==5){
                printf("\n");
                j=0;
                }
            }
            else
            {flag=1;break;}
    if(flag==0)
        return 1;            /*��low��high�ķ�Χ�ڸ�°ͺղ�����ȷ����1*/
    else
        return 0;               /*��low��high�ķ�Χ�ڸ�°ͺղ��벻��ȷ����0*/
}

int isGoldbach(int a)
{/*�ж�ż��a�Ƿ���ϸ�°ͺͲ���*/
   int i,flag=0;
   for(i=1;i<=a/2;i++)
   {
        if(isPrime(i)&& isPrime(a-i))     /*���i��a-i��Ϊ����������ϸ��ϲ���*/
        {
            flag=1;
            printf("%d=%d+%d ",a,i,a-i);
            break;
        }
   }
   if(flag==1)
        return 1;           /*a���ϸ�°ͺղ��뷵��1*/
   else
        return 0;          /*a�����ϸ�°ͺղ��뷵��0*/
}

int isPrime(int i)
{   /*�ж�o�Ƿ�������*/
    int n,flag=1;
    if(1==i)flag=0;                 /*1����������������Ҫ����1*/
    for(n=2;n<i;n++)
        if(i%n==0){flag=0;break;}  /*�����2~i-1֮��i���������ӣ���i��������,flag��0*/
    if(flag==1)
        return 1;           /*i����������1*/
    else
        return 0;          /*i�����ط���0*/
}

