#include "stdio.h"
#include <conio.h>
#include <graphics.h>

typedef struct BiTNode{
    char data;   /*����������*/
    struct BiTNode *lchild , *rchild;  /*ָ�����Ӻ��Һ���*/
} BiTNode , *BiTree;

CreatBiTree(BiTree *T){
    char c;
    gotoxy(5,5)  ;
    printf("Please input chareter to creat a BiTree\n") ;
    scanf("%c",&c);
    if(c == ' ') *T = NULL;
    else{
       *T = (BiTNode * )malloc(sizeof(BiTNode));  /*���������*/
        (*T)->data = c;    /*����������������*/
        CreatBiTree(&((*T)->lchild));  /*�ݹ�ش���������*/
        CreatBiTree(&((*T)->rchild));  /*�ݹ�ش���������*/
    }
}

printTree(BiTree T,int x,int y){
    char e[2] = {'\0','\0'};

    if(T){   /*�ݹ����������TΪ��*/
          { /*����һ����㣬������ͣ2��*/
           e[0] = T->data  ;
           circle(x,y,8)  ;
           settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
           outtextxy(x,y,e);
           sleep(2);
           }
        if(printTree(T->lchild,x-(200-y),y+20))  /*�������T��������*/
            line(x,y,x-(200-y),y+20);
        if(printTree(T->rchild,x+(200-y),y+20))  /*�������T��������*/
             line(x,y,x+(200-y),y+20)   ;
        return 1;
    }
    return 0;
}

main()
{
    BiTree T = NULL;
    int y = 100 ,x = 350;  /*���ö��������������*/
int   GraphDriver = DETECT;  
int GraphMode;
    int color;
    color = RED;
    initgraph( &GraphDriver, &GraphMode, "\\tc\\bgi" );  /* ��ʼ��ͼ��ϵͳ�������ļ�"\\tc\\bgi"��·���������ô���*/
    setcolor(color);  /*����ͼ����ɫ����ɫ*/
    CreatBiTree(&T);  /*����������*/
    printTree(T,x,y);  /*��̬��ʾ��������������*/
    getche();
    closegraph();
}

