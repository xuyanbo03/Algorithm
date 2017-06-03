#include "stdio.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10

typedef char ElemType;   /*��char���Ͷ���ΪElemType*/
typedef struct{        /*����һ��ջ����*/
    ElemType *base;
    ElemType *top;
    int stacksize;
}sqStack;


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


void  translate(ElemType e, sqStack *s){
     ElemType c , a;
     sqStack ss1;
    if(e>=97 && e<=122 )  printf("%c",e);
    else if(e == 'A') printf("%s","sae");
    else if(e == 'B') printf("%s","tsaedsae");
    else if(e == '(')
    {

        initStack(&ss1); /*��ʼ��ջss1��������������������ݴ�ջ��ȡ��*/
        Pop(&(*s),&c);  /*ע��*s�൱���������е�s*/
        a = c; /*�������ź�ĵ�һ��Ԫ��*/
        Pop(&(*s),&c); 
        while(c!=')'){
            Push(&ss1,a);
            Push(&ss1,c);
            Pop(&(*s),&c); 
       }
        Push(&ss1,a);        /*�����﷨�涨���к�����������һ����ջss1*/
       while(StackLen(ss1))  /*���������������*/
       {
         Pop(&ss1,&c);       /*ȡ��ss1�е�Ԫ��c*/
         translate(c,&ss1);  /*�ݹ�ص��ú��� translate��Ԫ��c���з���*/
       }
    }
}



main()
{
    ElemType e;
    sqStack s1,s2;
    initStack(&s1);   /*��ʼ��ջs1*/

    printf("Please input Devil language:\n");
    scanf("%c",&e);

    while(e != '#')
    {
        if(e=='A' || e=='B' || (e>=97 && e<=122) || e=='('|| e==')')
        {   /*�����ħ�����ԺϷ�*/
            Push(&s1,e);  /*��ջ*/

        }
        scanf("%c",&e);
    }


    initStack(&s2);  /*��ʼ��ջs2*/
    while(StackLen(s1))
    {
        Pop(&s1,&e);
        //printf("%c\n",e);
        Push(&s2,e);  /*��ħ�����Դ���������ջs2*/
    }

    printf("The mankind language is:\n");
      while(StackLen(s2))
      {
        Pop(&s2,&e);
        translate(e,&s2) ;
      }

     getche();
}



