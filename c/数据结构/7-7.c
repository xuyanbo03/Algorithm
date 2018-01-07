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


int match(char e,char c){
    if(e=='(' && c==')')return 1;
    if(e=='[' && c==']')return 1;
    return 0;
}

main()
{
    sqStack s;
    char c , e ;
    initStack( &s ) ;  /*��ʼ��һ����ջ*/
    scanf("%c",&c);  /*�����һ���ַ�*/
    while(c!='#'){   /*'#'Ϊ����Ľ�����־*/
        if(!StackLen(s))
            Push(&s,c);  /*���ջΪ�գ���˵��������ǵ�һ���ַ�����˱�����ջ��*/
        else
        {
             Pop(&s,&e);    /*ȡ��ջ��Ԫ��*/
             if(!match(e,c)){  /*�������Ԫ����ȡ����ջ�����бȽϣ����ƥ�䲻�ɹ�*/
                Push(&s,e);   /*�Ƚ�ԭջ��Ԫ��������ջ*/
                Push(&s,c);   /*�ٽ�����������ַ���ջ*/
               }
        }
        scanf("%c",&c);  /*������һ���ַ�*/
        }
    if(!StackLen(s))  printf("The brackets are matched\n");  /*���ջsΪ�գ���������ȫƥ��*/
    else  printf("The brackets are not matched\n");   /*���ջs��Ϊ�գ������Ų���ȫƥ��*/
    getche();

}

