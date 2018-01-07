#include "stdio.h"

typedef struct BiTNode{
    char data;   /*����������*/
    struct BiTNode *lchild , *rchild;  /*ָ�����Ӻ��Һ���*/
} BiTNode , *BiTree;
/*����һ�ö�����*/
CreatBiTree(BiTree *T){
    char c;
    scanf("%c",&c);
    if(c == ' ') *T = NULL;
    else{
       *T = (BiTNode * )malloc(sizeof(BiTNode));  /*���������*/
        (*T)->data = c;    /*����������������*/
        CreatBiTree(&((*T)->lchild));  /*�ݹ�ش���������*/
        CreatBiTree(&((*T)->rchild));  /*�ݹ�ش���������*/
    }
}
/*���ʶ�������㣬�������D�ַ����λ�ڶ������еĲ���*/
visit(char c,int level){
     if(c == 'D')
        printf("%c is at %d lever of BiTree\n",c,level);
}
/*����������*/
PreOrderTraverse(BiTree T,int level){
    if(T){   /*�ݹ����������TΪ��*/
        visit(T->data,level);  /*���ʸ����*/
        PreOrderTraverse(T->lchild,level+1);  /*�������T��������*/
        PreOrderTraverse(T->rchild,level+1);  /*�������T��������*/
    }
}

main()
{
   int level = 1;
   BiTree T = NULL;  /*�ʼTָ���*/
   CreatBiTree(&T);  /*����������*/
   PreOrderTraverse(T,level); /*�������������ҵ�����D�ַ����λ�ڶ������еĲ���*/
   getche();
}

