# include "stdio.h"

int isPrime(int a)
{  /*�ж�a�Ƿ�������������������1��������������0*/
    int i;
    for(i=2;i<=a-1;i++)
    if(a % i == 0)
        return 0;      /*��������*/
    return 1;       /*������*/
}

void PrimeFactor(int n)
{  /*�Բ���n�ֽ�������*/
    int i;
    if(isPrime(n))  printf("%d ",n);
    else
    {
        for(i=2;i<=n-1;i++)
            if(n % i == 0)
            {
                 printf("%d ",i);             /*��һ������һ����������*/
                 if(isPrime(n/i)) {            /*�жϵڶ��������Ƿ�������*/
                     printf("%d ",n/i);
                     break;                 /*�ҵ�ȫ��������*/
                    }
                else
                    PrimeFactor(n/i);        /*�ݹ�ص���PrimeFactor �ֽ�n/i */
            break;
            }
    }
}
main()
{
    int n;
    printf("Please input a integer for getting Prime factor\n")  ;
    scanf("%d",&n);
    PrimeFactor(n);   /*��n�ֽ�������*/
    getche();
}

