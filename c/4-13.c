#include "stdio.h"
deTobi(int a){
    /*��ʮ������aת��Ϊ�����Ʊ�ʾ������ӡ����Ļ��*/
    int i = 0 , stack[10] , r , s;
    do{
        r = a/2;   /*��*/
        s = a%2;   /*����*/
        stack[i] = s; 
         if(r!=0)
         {
            i++;      
            a = r;   /*��a����2�Ľ����Ϊ��һ������2�Ķ���*/
          }
       }
    while(r);     /*ѭ��ֱ����rΪ0Ϊֹ*/
    for(;i>=0;i--)
    printf("%d",stack[i]);
    printf("\n");
}

main()
{
    int a;
    printf("Please input a Decimal digit\n");
    scanf("%d",&a);
    deTobi(a);
    getche();
}

