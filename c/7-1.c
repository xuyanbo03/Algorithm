#include "stdio.h"
# define MAXSIZE 10
typedef struct{
    int * base;
    int length;
}sqlist ;

reverseSQ(sqlist *l){
    int low = 0 , high = l->length - 1;
    int buf , i;
    for(i=0;i<l->length/2;i++)
    {
        buf = l->base[low] ;
        l->base[low] = l->base[high];
        l->base[high] = buf;
        low++;
        high--;
    }
}

main()
{
    sqlist l;
    int a , i = 0;
    /*����һ��˳���*/
    l.base = (int *)malloc(sizeof(int)*MAXSIZE);
    l.length = 0;

    /*��������*/
    printf("Please input below 10 integer into the sqlist\n") ;
    printf("Type -1 for stopping input\n");
    scanf("%d",&a);
    while(a != -1 && i<=9)
    {
        l.base[i] = a;
        l.length++;
        i++;
        scanf("%d",&a);
    }

    /*���ԭ˳����е�����*/
    printf("The contents of the sqlist are\n");
    for(i=0;i<l.length;i++)
         printf("%d ",l.base[i]);
     printf("\n");

    reverseSQ(&l);    /*�͵�����˳���*/


    /*������ú��˳����е�����*/
    printf("The contents of the reversed sqlist are\n");
    for(i=0;i<l.length;i++)
        printf("%d ",l.base[i]);
       getche();

}