#include "stdio.h"
#include "math.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef  char ElemType;
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;

void initStack(sqStack *s)
{
    /*�ڴ��п���һ�������ռ���Ϊջ�ռ䣬�׵�ַ��ֵ��s->base*/
    s->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(!s->base) exit(0);     /*����ռ�ʧ��*/
    s->top = s->base;       /*�ʼ��ջ������ջ��*/
    s->stacksize = STACK_INIT_SIZE;   /*�������ΪSTACK_INIT_SIZE */
}
void Push(sqStack *s, ElemType e){
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

void Pop(sqStack *s , ElemType *e){
    if(s->top == s->base) return;
    *e = *--(s->top);     
}

int StackLen(sqStack s){
    return (s.top - s.base) ; 
}

main()
{
    ElemType c;
    sqStack s1;
    sqStack s2;
    int len,i,j,sum = 0;
    initStack(&s1);  /*����һ��ջs1��������Ŷ������ַ���*/

    printf("Please input a binary number and type '#' for end\n");
    /*����0/1�ַ���ʾ�Ķ�����������#����*/
    scanf("%c",&c);
    while(c!='#')
    {
        if(c=='0' || c=='1')
            Push(&s1,c); 
        scanf("%c",&c);
    }
    initStack(&s2);  /*����һ��ջs2��������Ű˽����ַ���*/
    len = StackLen(s1);  /*�õ�ջ�е�Ԫ�ظ����������������ĳ���*/
    for(i=0;i<len;i=i+3){
        for(j=0;j<3;j++){
             Pop(&s1,&c);  /*ȡ��ջ��Ԫ��*/
             sum = sum + (c-48) * pow(2,j);  /*ת��Ϊ�˽�����*/
             if(s1.base == s1.top) break;
             }
             Push(&s2,sum+48) ;  /*���˽��������ַ���ʽѹ��ջ��*/
             sum = 0;

          }

    printf("The Octal from is \n") ;
    while(s2.base != s2.top ){ /*����˽���ջ������*/
       Pop(&s2,&c);
       printf("%c",c);
    }
    getche();

}