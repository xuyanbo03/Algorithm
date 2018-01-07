#include "stdio.h"

typedef struct node{
    int data;
    int freq;
    struct node *prior;
    struct node *next;
}dbLNode,*dbLinkList;

/*����һ��˫��������������ͷָ��*/
dbLinkList GreatdbLinkList(int n){
   dbLinkList p,r,list=NULL;
   int e;
   int i;
    list = (dbLinkList)malloc(sizeof(dbLNode));  /*����ͷ���head,ͷ����в��������*/
    list->next = list->prior = NULL;
    for(i=1;i<=n;i++){
        scanf("%d",&e);
        p = (dbLinkList)malloc(sizeof(dbLNode));
        p->data = e;
        p->freq = 0;
        p->next = NULL;
        p->prior = NULL;
        if(!list->next) {
            list->next = p;      /*��һ�����*/
            p->prior = list;
            }
        else{
            r->next = p;   /*˫����������Ľ��*/
            p->prior = r;
            }

        r = p;
    }
    return list;
}

/*����˫��������ָ���Ľ�㣬������������*/
visit(dbLinkList *l,int x){
    dbLinkList p = *l, q, r, s;
    p = p->next;   /*pָ���һ�����*/
    while(p->data != x && p!=NULL)p = p->next;
    if(p == NULL) {printf("Input error!\n");return;}
    p->freq ++;
    printf("Visiting this node\n");
    while((p->prior)!=*l && p->freq > p->prior->freq)
    {

           /*ʵ��˫��������Ľ���*/
            q = p->prior;
            r = p->next;
            s = p->prior->prior;
            p->prior = q->prior;
            p->next = q;
            q->prior = p;
            q->next = r;
            r->prior = q;
            s->next = p;
    }

}

TransdbLinkList(dbLinkList l)
{   /*��������˫������,����ӡ��ÿ������е����ݺͷ���Ƶ��*/
    l = l->next;
    while(l!=NULL){
        printf("(data:%d ,freq:%d)--> ",l->data,l->freq);
        l = l->next;
        }

     printf("X\n\n");

}

main()
{
   dbLinkList l;
   int d;
   printf("Input five integer to creat a doubly link list\n");
   l = GreatdbLinkList(5);
   TransdbLinkList(l);

   printf("Please input the data that you want to vist\n");

   scanf("%d",&d);
   while(d!=0){
   visit(&l,d);
   TransdbLinkList(l);
   scanf("%d",&d);
   }
   getche();
}

