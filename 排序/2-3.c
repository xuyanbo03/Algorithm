#include "stdio.h"
insertsort(int a[],int n)                        /*ֱ�Ӳ�������*/
{
    int i,j;
    for(i=2;i<=n;i++)
    {
        a[0] = a[i];
        j = i - 1;
        while(j>0 && a[0]>a[j])                    /*�ı��ж�������ʵ�ִӴ�С������*/
            a[j+1] = a[j--];
        a[j+1] = a[0];                        /*��Ԫ��a[0]����ָ��λ��*/
    }
}

main()
{
    int i,a[11] = {-111,2,5,6,3,7,8,0,9,12,1};        /*��ʼ�����У�a[0]����������*/
    printf("The orginal data array is\n") ;
    for(i=1;i<=10;i++)                        /*��ʾԭ����֮�е�Ԫ��*/
        printf("%d ",a[i]);
    insertsort(a,10);                            /*��������*/
    printf("\nThe result of insertion sorting for the array is\n");
    for(i=1;i<=10;i++)
        printf("%d ",a[i]);                        /*��������Ľ��*/
    getche();
}

