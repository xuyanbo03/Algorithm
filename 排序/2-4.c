#include "stdio.h"
void selectsort(int k[],int n)                /*ѡ������*/
{
    int i,j,max;
    for(i=1;i<=n-1;i++){
         max = i;
         for(j=i+1;j<=n;j++)            /*�ں�n-i+1��Ԫ�����ҵ���С��Ԫ��λ��*/
         if(k[j] > k[max])
            max = j;                /*��min��¼����СԪ�ص�λ��*/
           if(max != i){                /*�����С��Ԫ�ز�λ�ں�n-i+1��Ԫ�ص���1��*/
                k[0] = k[max] ;
                k[max] = k[i];            /*Ԫ�صĽ���*/
                k[i] = k[0];
            }
         }
}

main()
{
    int i,a[11] = {-111,2,5,6,3,7,8,0,9,12,1};        /*��ʼ�����У�a[0]����������*/
    printf("The orginal data array is\n") ;
    for(i=1;i<=10;i++)                        /*��ʾԭ����֮�е�Ԫ��*/
        printf("%d ",a[i]);
    selectsort(a,10);                         /*ִ��ѡ������*/
    printf("\nThe result of selection sorting for the array is\n");
    for(i=1;i<=10;i++)
        printf("%d ",a[i]);                        /*��������Ľ��*/
    getche();
}

