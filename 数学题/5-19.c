#include"stdio.h"
#define max 100

Perm(int a[], int n ,int s ,int r[], int m){
    int i,j,k,flag=0;
    int b[max];                    /*����b���������*/
    for(i=0;i<n;i++){
        flag = 1;
        r[s] = a[i];                /*��������a�е�i��Ԫ�ص�����r*/
        j = 0;
        for(k=0;k<n;k++)            /*����������b*/
            if(i != k){
                b[j] = a[k];
                j++;
            }                   
        Perm(b,n-1,s+1,r,m);        /*ȫ����������b*/
    }
if(flag == 0){                /*�õ�һ�����н��*/
           printf("\n");
           for(k=0;k<m;k++)
            printf("%d",r[k]);        /*���������н��������r�е�����*/
        printf("\n");
    }
}

main()
{
    int a[max] , r[max];
    int i,n;
    printf("Please input the number of digit inthe array\n");
    scanf("%d",&n);                /*��������е�������Ԫ�صĸ���*/
    printf("Please input a string for array\n");
    for(i=0;i<n;i++)                /*���������е�Ԫ�أ�������*/
        scanf("%d",&a[i]);
    Perm(a,n,0,r,n);                /*ȫ���в���*/
    getche();
}

