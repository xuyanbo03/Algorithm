/******************************************Dynamic Sort*************************************************/
#include <string.h> 
#include <stdio.h> 
#include <malloc.h>

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

/*�������в�����*/
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



/*���������ð�������㷨*/
void Sort(LinkList q)
{
    LNode *p=q;
    int t,i,j,k=0;
    while(p) {k++; p=p->next;}
    p=q;
    for(i=0;i<k-1;i++)
    {
        for(j=0;j<k-i-1;j++)
        {
            if(p->data>p->next->data)
            {
              t=p->data;
              p->data=p->next->data;
              p->next->data=t;
            }
            p=p->next;
        }
    p=q;
    }

}

/*��ӡ���������������е�����*/
void Print(LinkList q)
{
    while(q)
    {
        printf("%d ",q->data);
        q=q->next;
    }
}

/*������*/
main()
{
    ElemType e;
    LinkList  l,q;    /*����һ������l*/
    printf("Please input some integer digit and type 0 for end\n");
    q=l=GreatLinkList(1);   /*����һ�������㣬q��lָ��ý��*/

    scanf("%d",&e);
    while(e)             /*ѭ�����������ݣ�ͬʱ���������ɵĽ��*/
    {
      insertList(&l,q,e) ;
      q=q->next;
      scanf("%d",&e);
    }


    Sort(l);
    Print(l);
    getche();
}

