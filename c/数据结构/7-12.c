#include "stdio.h"

typedef struct QNode{     /*������н����*/
    char data;
    struct QNode *next;
} QNode , *QueuePtr;

typedef struct{                /*����һ��������*/
    QueuePtr front;         /*��ͷָ��*/
    QueuePtr rear;            /*��βָ��*/
}LinkQueue;

initQueue(LinkQueue *q){
    /*��ʼ��һ���ն���*/
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); /*����һ��ͷ��㣬��ͷ��βָ��                                                                ָ��ý��*/
    if( !q->front) exit(0);            /*����ͷ���ʧ��*/
    q->front->next = NULL;        /*ͷ���ָ������NULL*/
}

EnQueue(LinkQueue *q, char e){        /*����в���*/
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));    /*����һ������Ԫ�ؽ��*/
    if( !q->front) exit(0);                    /*����ͷ���ʧ��*/
    p->data = e;                        /*��Ԫ��e�����*/
    p->next = NULL;                    /*�޸Ķ�βָ��*/
    q->rear ->next = p;
    q->rear = p;
}
DeQueue(LinkQueue *q, char *e){
    /*�������q��Ϊ�գ�ɾ��q�Ķ�ͷԪ�أ���e������ֵ*/
    QueuePtr p;
    if(q->front == q->rear) return;  /*����Ϊ�գ�����*/
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p) q->rear = q->front;  /*�����ͷ���Ƕ�β�����޸Ķ�βָ��*/
    free(p);
}


printTriangle(int n){
    LinkQueue q;
    char e,a,b ;
    int i,j;
    initQueue(&q);          /*��ʼ������*/
    printf("Input the the charecter(+/-) of the row.1\n");
    for(i=0;i<n;i++){       /*�����һ�еķ��ţ��������*/
       scanf("%c",&e);
       EnQueue(&q,e);
       }

    printf("The charecter triangle is like\n");
     for(i=0;i<n;i++){           /*���Ʒ������ǵ�����*/
        for(j=0;j<i;j++)
            printf(" ");           /*���������ʽ����ӡ�ɵ�������״*/
        DeQueue(&q,&a);         /*�����У���ӡÿ�еĵ�һ������*/
        printf("%c ",a);
        for(j=0;j<n-i-1;j++)    /*�������ÿһ�У���i�����n-i������*/
        {
           DeQueue(&q,&b);      /*������*/
           printf("%c ",b);
           if(a == b)  EnQueue(&q,'+'); /*���β������Ԫ��*/
           else EnQueue(&q,'-');
           a = b;
        }
        printf("\n");    /*���������ʽ����ӡ�ɵ�������״*/
    }
}

main()
{
    int n;
    printf("Please input the number of '+' or '-' of the row.1 \n");
    scanf("%d",&n);
    getchar();
    printTriangle(n);
    getche();
}
