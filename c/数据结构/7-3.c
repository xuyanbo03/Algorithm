#include "stdio.h"

/*����intΪElemType����*/
typedef int ElemType;

/*��������Ľ������*/
typedef struct node{
    ElemType data;   /*������*/
    struct node *next;  /*ָ����*/
}LNode,*LinkList;

/*����һ������Ϊn����������������*/
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

/*�������в����㣬����ý����������д������e*/
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

void insertNode(LinkList *q1,LinkList *q2,LinkList *p,LinkList *l2){
     if(*q1 == *q2)
     {
         (*p)->next = *q2;
         *l2 = *q2 = *q1 = *p;

     }
     else
     {
        (*q2)->next = *p;
        (*p)->next = *q1;
        (*q2) = (*q2)->next;
     }
}

void MergeLink(LinkList l1, LinkList l2 ,LinkList *l3)
{
    /*������l1,l2����鲢��l3ָ��鲢���������*/
    LinkList p,q1,q2;
    q1 = q2  = l2; /*l3ָ��l2*/
    p = l1;
    while(p!=NULL && q1!=NULL){
        if(p->data >= q1->data) {
        q2 = q1;
        q1 = q1->next;
        }
        else{
            l1 = l1->next ;
            insertNode(&q1,&q2,&p,&l2);     /*��pָ��Ľ����q2֮ǰq1֮��*/
           // q2 = q2->next;
            p = l1;
        }
    }

    if(q1 == NULL) q2->next = p;

    *l3 = l2;


}

main()
{
    ElemType e;
    LinkList  l1,l2,l3,q;

    printf("Please input the contents of Link1\n");
    q=l1=GreatLinkList(1);   /*����һ�������㣬q��lָ��ý��*/

    scanf("%d",&e);
    while(e)             /*ѭ�����������ݣ�ͬʱ���������ɵĽ��*/
    {
      insertList(&l1,q,e) ;
      q=q->next;
      scanf("%d",&e);
    }

    printf("Please input the contents of Link2\n");
    q=l2=GreatLinkList(1);   /*����һ�������㣬q��lָ��ý��*/

    scanf("%d",&e);
    while(e)             /*ѭ�����������ݣ�ͬʱ���������ɵĽ��*/
    {
      insertList(&l2,q,e) ;
      q=q->next;
      scanf("%d",&e);
    }

    MergeLink(l1,l2,&l3);  /*�ϲ�l2,l2����l3ָ��ϲ��������*/

    q = l3;

    printf("The merge of link1 and link 2 is\n");
    while(q)            /*��ӡ���ϲ��������*/
    {
        printf("%d ",q->data) ;
        q = q->next;
    }
    getche();


}
