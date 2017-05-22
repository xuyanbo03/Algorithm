#include "stdio.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10


typedef char ElemType;   /*��char���Ͷ���ΪElemType*/

typedef struct QNode{     /*������н����*/
    ElemType data;
    struct QNode *next;
} QNode , *QueuePtr;

typedef struct{      /*����һ��������*/
    QueuePtr front;   /*��ͷָ��*/
    QueuePtr rear;    /*��βָ��*/
}LinkQueue;

typedef struct{        /*����һ��ջ����*/
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;


initQueue(LinkQueue *q){
    /*��ʼ��һ���ն���*/
    q->front = q->rear = (QueuePtr)malloc(sizeof(QNode)); /*����һ��ͷ��㣬��ͷ��βָ��                                                                ָ��ý��*/
    if( !q->front) exit(0);     /*����ͷ���ʧ��*/
    q->front->next = NULL;     /*ͷ���ָ������NULL*/
}

EnQueue(LinkQueue *q, ElemType e){      /*����в���*/
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));  /*����һ������Ԫ�ؽ��*/
    if( !q->front) exit(0);     /*����ͷ���ʧ��*/
    p->data = e;                /*��Ԫ��e�����*/
    p->next = NULL;             /*�޸Ķ�βָ��*/
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

initStack(sqStack *s)
{
    /*�ڴ��п���һ�������ռ���Ϊջ�ռ䣬�׵�ַ��ֵ��s->base*/
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base) exit(0);     /*����ռ�ʧ��*/
    s->top = s->base;       /*�ʼ��ջ������ջ��*/
    s->stacksize = STACK_INIT_SIZE;   /*�������ΪSTACK_INIT_SIZE */
}

Push(sqStack *s, ElemType e){        /*��ջ����*/
    if(s->top - s->base >= s->stacksize){
    /*ջ����׷�ӿռ�*/
    s->base = (ElemType *)realloc(s->base, (s->stacksize + 
    STACKINCREMENT)*sizeof(ElemType));
    if(!s->base) exit(0);   /*�洢����ʧ��*/
    s->top = s->base + s->stacksize;
    s->stacksize = s->stacksize + STACKINCREMENT; /*����ջ���������*/
    }
    *(s->top) = e;  /*��������*/
        s->top++;
}

Pop(sqStack *s , ElemType *e){   /*��ջ����*/
    if(s->top == s->base) return;  /*��ջ��Ԫ�ص���*/
    *e = *--(s->top);              /*�޸�ջ��ָ��*/
}

int StackLen(sqStack s){     /*���ջs�Ĵ�С*/
    return (s.top - s.base) ; 
}


main()
{
    sqStack s;
    LinkQueue q;
    ElemType e,r1,r2;
    int flag = 1, i, len;

    initQueue(&q);  /*��ʼ��һ������*/
    initStack(&s);  /*��ʼ��һ��ջ*/
    printf("Please input a string ,type '@' for end\n");
    scanf("%c",&e);
    while(e != '@'){       /*������жϵ��ַ�����*/
        Push(&s,e);
        EnQueue(&q,e);
        scanf("%c",&e);
    }

    len =  StackLen(s)/2;  /*����ַ����еĳ���*/

    for(i=0;i<len;i++)
    {
        Pop(&s,&r1);     /*��ջ��������r1��ջ��Ԫ�ط���*/
        DeQueue(&q,&r2); /*�����в�������r2����ͷԪ�ط���*/
        if(r1 != r2) { flag = 0; break;}
    }
    if(flag == 1)printf("It is a circle string.\n");
    else printf("It is not a circle string.\n") ;
    getche();
}

