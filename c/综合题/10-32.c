#include "stdio.h"

typedef char ElemType;
typedef struct QNode{
    ElemType data;
    struct QNode *next;
} QNode , *QueuePtr;
typedef struct{
    QueuePtr front;   //��ͷָ��
    QueuePtr rear;    //��βָ��
}LinkQueue;

initQueue(LinkQueue *q){
    /*��ʼ��һ���ն���*/
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); /*����һ��ͷ��㣬��ͷ��βָ��                                                                ָ��ý��*/
    if( !q->front) exit(0);     /*����ͷ���ʧ��*/
    q->front->next = NULL;     /*ͷ���ָ������NULL*/
}

EnQueue(LinkQueue *q, ElemType e){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));  /*����һ������Ԫ�ؽ��*/
    if( !q->front) exit(0);     /*����ͷ���ʧ��*/
    p->data = e;
    p->next = NULL;
    q->rear ->next = p;
    q->rear = p;
}

int getQueueLen(LinkQueue *q)
{
    QNode *p;
    int count = 0;
    p = q->front;
    while(p!=q->rear)
    {
        p = p->next;
        count++;
    }
    return count;
}

main()
{
    LinkQueue  q;
    char e;
    initQueue(&q);					/*��ʼ��һ������q*/
    printf("Please input a string into a queue\n");
    scanf("%c",&e);
    while(e!='@'){
        EnQueue(&q,e);				/*������������ַ�������@��ʾ����*/ 
        scanf("%c",&e);
    }
    printf("The length of the Queue is %d\n",getQueueLen(&q));	/*������еĳ���*/
    getche();
}
