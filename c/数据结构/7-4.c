#include "stdio.h"

/*�����㶨��*/
typedef struct node{
    int number;  /*���*/
    int psw;    /*��������*/
    struct node *next;
} LNode,*LinkList;


void insertList(LinkList *list,LinkList q,int e1,int e2){
    LinkList p;
    p=( LinkList)malloc(sizeof(LNode));
    p->number = e1;
    p->psw = e2;
    if(!*list){
    *list=p;
    p->next=NULL;
    }
    else{
        p->next=q->next;
        q->next=p;
    }    
}



CreatJoseph(LinkList *jsp , int n)
{
    LinkList  q = NULL , list = NULL;
    int i ,  e2;
     printf("Please input the password for people in the Joseph circle\n");
    for(i=0;i<n;i++){
        scanf("%d",&e2);
        insertList(&list,q,i+1,e2);   /*��qָ��Ľ���������µĽ��*/
        if(i == 0) q = list;   /*��һ��֮����ͷ��㣬qҲָ��ͷ���*/
        else q = q->next;        /*qָ����һ���*/
        }
    q->next = list; /*�γ�ѭ������*/

    *jsp = list;  //����
}


exJoseph(LinkList *jsp, int m)
{
    LinkList p ,q;
    int i;
    q = p = *jsp ;
    while(q->next != p) q=q->next;  /*qָ��p��ǰһ�����*/

    printf("The order of a column is\n") ;
    while(p->next != p){
    for(i=0;i<m-1;i++)
    {                    /*pָ��Ҫɾ���Ľ��,qָ��p��ǰһ�����*/
        q = p;
        p = p->next;
    }
    q->next = p->next;
    printf("%d ",p->number);
    m = p->psw;
    free(p);
    p = q->next;
    }
    printf("\nThe last person in the circle is %d\n",p->number);    /*��ӡ��������ڶ��е��˵ı��*/
}

main()
{
     LinkList jsp;
     int n , m;
     printf("Please input number of the people in the Joseph circle\n");
     scanf("%d",&n) ;
     CreatJoseph(&jsp, n);
     printf("Please input the first maximum number\n");
     scanf("%d",&m) ;
     exJoseph(&jsp,m) ;
     getche();
}
