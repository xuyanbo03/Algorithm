#include "stdio.h"
typedef int ElemType;
typedef struct node{
    ElemType data;   /*������*/
    struct node *next;  /*ָ����*/
}Lnode,*LinkList;

LinkList GreatLinkList(int n){
    LinkList p,r,list=NULL;
    ElemType e;
    int i;
    for(i=1;i<=n;i++){
        scanf("%d",&e);
        p=(LinkList)malloc(sizeof(Lnode));
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

Lnode * getPtr(Lnode *head, int pos)
{
     Lnode *p = head;
     int i;
     for(i=1;i<pos;i++)
     {
        p = p->next;
     }
     return p;
}

main()
{
    LinkList l,p,q;
    int i;
    printf("Please input 10 integer to create a linklist\n");
    l = GreatLinkList(10);

    /*ɾ�������е�5�����*/
            p = getPtr(l,4);
            q = p->next;
            p->next = p->next->next;
            free(q);

    /*��������е�Ԫ��*/
    printf("The linklist after deleting the fifth node\n");
    p = l;
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
    getche();
}
