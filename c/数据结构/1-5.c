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
DeQueue(LinkQueue *q, ElemType *e){
    /*�������q��Ϊ�գ�ɾ��q�Ķ�ͷԪ�أ���e������ֵ*/
    QueuePtr p;
    if(q->front == q->rear) return;  /*����Ϊ�գ�����*/
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p) q->rear = q->front;  /*�����ͷ���Ƕ�β�����޸Ķ�βָ��*/
    free(p);
}
/*���Ժ���*/
main()
{
    ElemType e;
    LinkQueue  q;
    initQueue(&q);           /*��ʼ��һ������q*/
    printf("Please input a string into a queue\n");
    scanf("%c",&e);
    while(e!='@'){
        EnQueue(&q,e);   /*������������ַ�������@��ʾ����*/ 
        scanf("%c",&e);
    }
    printf("The string into the queue is\n");
    while(q.front != q.rear){   /*�������е�Ԫ�س����У�����ӡ����Ļ��*/
        DeQueue(&q,&e);
        printf("%c",e);
    }
    printf("\n");
    getche();
}

