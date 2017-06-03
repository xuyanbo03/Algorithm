#include "stdio.h"

typedef int ElemType;

typedef struct node{
    ElemType data;   /*������*/
    struct node *next;  /*ָ����*/
}LNode,*LinkList;

LinkList GreatLinkList(int n){
    LinkList p,r,list=NULL;
    ElemType e;
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&e);
        p=(LinkList)malloc(sizeof(LNode));
        p->data=e;
        p->next=NULL;
        if(!list)
            list=p;
        else
            r->next=p;
        r=p;
    }
    return list;
}

void insertList(LinkList *list,LinkList q,ElemType e){
    LinkList p;
    p=( LinkList)malloc(sizeof(LNode));
    p->data=e;
    if(!*list){
    *list=p;
    p->next=NULL;
    }
    else{
        p->next=q->next;
        q->next=p;
    }    
}

void delLink(LinkList *list ,LinkList q){
    LinkList r;
    if(q==list){
        *list=q->next;
        free(q);
    }
    else{
        for(r=*list;r->next!=q;r=r->next);
        if(r->next!=NULL){
            r->next=q->next;
            free(q);
            }
    }
}

void  destroyLinkList(LinkList *list){
    LinkList p,q;
    p=*list;                
    while(p){
    q=p->next;
    free(p);
    p=q;
    }
    *list=NULL;
} 

main()
{
    int e,i;
    LinkList l,q;
    q=l=GreatLinkList(1);   /*����һ�������㣬q��lָ��ý��*/
    scanf("%d",&e);
    while(e)             /*ѭ�����������ݣ�ͬʱ���������ɵĽ��*/
    {
      insertList(&l,q,e) ;
      q=q->next;
      scanf("%d",&e);
    }
    q=l;
    printf("The content of the linklist\n");
    while(q)          /*��������е�����*/
    {
      printf("%d ",q->data);
      q=q->next;
    }
    q=l;
    printf("\nDelete the fifth element\n");
    for(i=0;i<4;i++)    /*��ָ��qָ�������5��Ԫ��*/
    {
        q=q->next;
    }
    delLink(&l,q);     /*ɾ��q��ָ�Ľ��*/
    q=l;
    while(q)            /*��ӡ��ɾ����Ľ��*/
    {
      printf("%d ",q->data);
      q=q->next;
    }
    destroyLinkList(&l);  /*�ͷŵ�������*/
    getche();
}

