#include "stdio.h"
#include "math.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef  int ElemType;
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;
/*��ʼ��ջ*/
void initStack(sqStack *s)
{
    /*�ڴ��п���һ�������ռ���Ϊջ�ռ䣬�׵�ַ��ֵ��s->base*/
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base) exit(0);				/*����ռ�ʧ��*/
    s->top = s->base;				/*�ʼ��ջ������ջ��*/
    s->stacksize = STACK_INIT_SIZE; 	/*�������ΪSTACK_INIT_SIZE */
}
/*��ջ��������eѹ��ջ��*/
void Push(sqStack *s, ElemType e){
    if(s->top - s->base >= s->stacksize){
    /*ջ����׷�ӿռ�*/
    s->base = (ElemType *)realloc(s->base, (s->stacksize + 
    STACKINCREMENT)*sizeof(ElemType));
    if(!s->base) exit(0);                                /*�洢����ʧ��*/
    s->top = s->base + s->stacksize;
    s->stacksize = s->stacksize + STACKINCREMENT;        /*����ջ���������*/
    }
    *(s->top) = e;                                    		 /*��������*/
        s->top++;
}
/*��ջ��������e��ջ��Ԫ�ط���*/
void Pop(sqStack *s , ElemType *e){
    if(s->top == s->base) return;
    *e = *--(s->top);     
}

int f(int n)
{
    int r = 1, e;
    sqStack stack;
    initStack(&stack);				/*��ʼ��ջ*/
        while(n!=0){
            Push(&stack,n);			/*�����ֳ�n*/
            n = n/2;
        }
        while(stack.top!=stack.base)
        {
            Pop(&stack,&e);
            r = r * e;
        }
        return r;
}

main()
{
    printf("The result for conversion of recursion to non recursion is\n");
    printf("f(5)=%d \n",f(5));
    getche();
}
