#include "stdio.h"
#include "math.h"
#define STACK_INIT_SIZE 20
#define STACKINCREMENT 10
/*�����ջ*/
typedef  char ElemType;
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
    if(!s->base) exit(0);					/*����ռ�ʧ��*/
    s->top = s->base;					/*�ʼ��ջ������ջ��*/
    s->stacksize = STACK_INIT_SIZE;		/*�������ΪSTACK_INIT_SIZE */
}
/*��ջ��������eѹ��ջ��*/
void Push(sqStack *s, ElemType e){
    if(s->top - s->base >= s->stacksize){
    /*ջ����׷�ӿռ�*/
    s->base = (ElemType *)realloc(s->base, (s->stacksize + 
    STACKINCREMENT)*sizeof(ElemType));
    if(!s->base) exit(0);								/*�洢����ʧ��*/
    s->top = s->base + s->stacksize;
    s->stacksize = s->stacksize + STACKINCREMENT;		/*����ջ���������*/
    }
    *(s->top) = e;									/*��������*/
        s->top++;
}
/*��ջ��������e��ջ��Ԫ�ط���*/
void Pop(sqStack *s , ElemType *e){
    if(s->top == s->base) return;
    *e = *--(s->top);     
}

/*�����ջs��ǰ�ĳ���*/
int StackLen(sqStack s){
    return (s.top - s.base) ; 
}

void ADD(sqStack *s1,sqStack *s2,sqStack *s3)
{
char a1,a2,a3,c=0; 				/*a1,a2�ֱ��ŴӶ�ջs1,s2��ȡ���ģ����ݣ�Ԫ�أ�
a3=a1+a2,c�д�Ž�λ*/
    while(StackLen(*s1)!=0 && StackLen(*s2)!=0)
    {
         Pop(s1,&a1);					/*ȡ��s1ջ��ջ��Ԫ�ظ�a1*/
         Pop(s2,&a2);					/*ȡ��s2ջ��ջ��Ԫ�ظ�a2*/
         a3 = (a1-48) + (a2-48) + c + 48;		/*���*/
         if(a3>'9')
         {
               a3 = a3 - '9' + 47;			/*������λ�����*/
               c = 1;
          }
          else
              c = 0;					/*��������λ*/
         Push(s3,a3);					/*�������ջs3*/
     }
     if(StackLen(*s1)!=0)					/*ջs1��Ϊ�յ����*/
     {
        while(StackLen(*s1)!=0)
        {
           Pop(s1,&a1);					/*ȡ��s1ջ��ջ��Ԫ�ظ�a1*/
           a3 = a1 + c ;					/*���λ��־c���*/
           if(a3>'9')
           {
               a3 = a3 - '9' + 47;			/*������λ�����*/
               c = 1;
           }
          else
              c = 0;					/*��������λ*/
           Push(s3,a3);					/*�������ջs3*/
        }
     }
     else if(StackLen(*s2)!=0)				/*ջs1��Ϊ�յ����*/
     {
        while(StackLen(*s2)!=0)
        {
           Pop(s2,&a2);					/*ȡ��s1ջ��ջ��Ԫ�ظ�a1*/
           a3 = a2 + c;					/*���λ��־c���*/
           if(a3>'9')
           {
               a3 = a3 - '9' + 47;			/*������λ�����*/
               c = 1;
           }
          else
              c = 0;					/*��������λ*/
           Push(s3,a3);					/*ջs1��Ϊ�յ����*/
        }
     }
     if(c==1)
        Push(s3,'1');					/*�������н�λ�����ַ���1����ջs3*/
}

main()
{
    char e;
    sqStack s1,s2,s3;
    initStack(&s1);							/*��ʼ����ջs1����ż���*/
    initStack(&s2);							/*��ʼ����ջs2����ż���*/
    initStack(&s3);							/*��ʼ����ջs3����Ž��*/
    printf("Please input the first integer\n");		/*�����һ�����ⳤ����������#����β*/
    scanf("%c",&e);
    while(e!='#')
    {
       Push(&s1,e);							/*���������ַ�������ջs1*/
       scanf("%c",&e);
    }
    getchar();								/*���ջس���*/
    printf("Please input the second integer\n");		/*����ڶ������ⳤ����������#����β*/
    scanf("%c",&e);
    while(e!='#')
    {
       Push(&s2,e);							/*���������ַ�������ջs2*/
       scanf("%c",&e);
    }
    ADD(&s1,&s2,&s3);						/*�ӷ����㣬����������s3��*/
    printf("The result is\n");
    while(StackLen(s3)!=0)					/*����������ӡ����Ļ��*/
    {
        Pop(&s3,&e);
        printf("%c",e);
    }
    getche();
}
