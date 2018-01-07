#include "stdio.h"

void swap(int *a,int *b)
{                            /*������Ԫ��λ�õĽ���*/
  int tmp;
  tmp = *a;
  *a = *b;
  *b = tmp;
}
void quicksort(int k[], int s,int t)
{                            /*��������*/
    int i,j;
    if(s<t){
        i = s;
        j = t+1;
        while(1){
            do i++;
            while(!(k[s]>=k[i] || i==t));        /*�ظ�ִ��i++����*/
            do j--;
            while(!(k[s]<=k[j] || j==s));        /*�ظ�ִ��j--����*/
            if(i<j)
                swap(&k[i],&k[j]);            /*����k[i]��k[j]��λ��*/
            else
                break;

        }
        swap(&k[s],&k[j]);                /*������׼Ԫ����k[j]��λ��*/
        quicksort(k,s,j-1);                    /*�ݹ������׼Ԫ��ǰ���������*/
        quicksort(k,j+1,t);                    /*�ݹ������׼Ԫ�غ����������*/
    }
}

main()
{
    int k[10]={2,5,6,3,7,8,0,9,12,1} , i;
    printf("The orginal data array is\n") ;
    for(i=0;i<10;i++)                        /*��ʾԭ����֮�е�Ԫ��*/
        printf("%d ",k[i]);
    quicksort(k,0,9);                        /*��������*/
    printf("\nThe result of quick sorting for the array is\n");
    for(i=0;i<10;i++)                         /*��ʾ�����Ľ��*/
        printf("%d ",k[i]);
    getche();
}

