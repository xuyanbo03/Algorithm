#include "stdio.h"

void sort(int w[], int t[], int n)
{
    int i,j,tmp;
    int *w_tmp= (int *)malloc(sizeof(int) * n);/*��̬����һ����ʱ���飬���w[]�е����ݣ���������*/
    for(i=0;i<n;i++)
        t[i] = i;                            /*��ʼ������t*/
    for(i=0;i<n;i++)
        w_tmp[i] = w[i];
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)                /*ð������ʵ��*/
            if(w_tmp[j]>w_tmp[j+1])
            {
                tmp = w_tmp[j];
                w_tmp[j] = w_tmp[j+1];
                w_tmp[j+1] = tmp;
                tmp = t[j];
                t[j] = t[j+1];
                t[j+1] = tmp;
            }
}

void Loading(int x[],int w[],int c,int n)
{
    int i , s = 0 ;
    int *t = (int *)malloc(sizeof(int) * n); /*��̬����һ����ʱ���飬���w[]���±꣬���t[i],t[j],i<j����w[i]��w[j]*/
    sort(w,t,n);                        /*����������t[]���w[]���±�*/
    for(i = 0;i<n;i++)
    x[i] = 0;        /*��ʼ������x[]*/
    for(i=0;i<n && w[t[i]]<=c; i++){
        x[t[i]] = 1;                    /*����t[i]����װ��װ�������*/
        c = c - w[t[i]];                /*����c�д�Ż�����ʣ��������*/
        }
}

main()
{
    int x[5],w[5],c,i;
    printf("Please input the maximum loading of the sheep\n");
    scanf("%d",&c);                        /*������������������*/
    printf("Please input the weight of FIVE box\n");
    for(i=0;i<5;i++)                        /*����ÿ����װ�������*/
        scanf("%d",&w[i]);
    Loading(x,w,c,5);                    /*��������װ��*/
    printf("The following boxes will be loaded\n");
    for(i=0;i<5;i++)                        /*������*/
    {
        if(x[i] == 1)     printf("BOX:%d ",i) ;
    }
    getche();
}

