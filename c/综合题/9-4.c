#include "stdio.h"
int x[100];                 /*����x�������·��*/
int val[100] = {-1};        /*�����Ʒ�ĵ���*/
int weight[100] = {-1};     /*�����Ʒ������*/

int isOverLoad(int n,int c){
     int i,w = 0;
     for(i=0;i<n;i++)
        w = w + x[i] * weight[i];
     if(w  > c) return 1;       /*����*/
     else return 0;
}

int getVal(int n){
    int i,v = 0;
    for(i=0;i<n;i++)
        v = v + x[i] * val[i];
    return v;
}

knap_1(int n , int flag ,int c,int *price){  /*�ҵ���Ʒװ������߼�ֵ��*/
    int i,j,p;

    if(isOverLoad(n,c))return;        /*��֦*/

    if(n == flag){
        p =getVal(n);
        if(*price< p) *price = p;
        return;
    }
    for(i=0;i<=1;i++)
    {
        x[n] = i;
        knap_1(n+1,flag,c,price);
    }
}

int knap_2(int n , int flag ,int c,int price){  /*�ҵ���Ʒװ������ѷ���*/
    int i,j,p;
    if(isOverLoad(n,c))return ;        /*��֦*/
    if(n == flag){
        p =getVal(n);
        if(price == p) {
            printf("--------bag---------\n") ;
            for(j=0;j<n;j++)
            if(x[j]==1){
                printf("| |P%d:         |  |\n",j);
                printf("| |weight:%2d kg|  |\n",weight[j]);
                printf("| |price: %2d $ |  |\n\n",val[j]) ;
                }
             printf("--------------------\n\n") ;
             getche();
                return ;
        };
        return ;
    }
    for(i=0;i<=1;i++)
    {
        x[n] = i;
        knap_2(n+1,flag,c,price);
    }
}
main()
{
    int price=0, n ,c,i;
     printf("Input the number of products\n");
     scanf("%d",&n);
     printf("Input the weight of each product\n");
     for(i=0;i<n;i++)
        scanf("%d",&weight[i]);
     printf("Input the price of each product\n");
     for(i=0;i<n;i++)
         scanf("%d",&val[i]);
     printf("Input the limit weight the bag can overload\n");
        scanf("%d",&c);
    knap_1(0,n,c,&price);
    knap_2(0,n,c,price);
    printf("The grass price :%d $",price);
    getche();
}

