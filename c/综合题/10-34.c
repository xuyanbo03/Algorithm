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

int PreOrderTraverse(BiTree T,int level){
    int l;
    if(T){   /*�ݹ����������TΪ��*/
        if(T->data=='C')
            return level;
        l = PreOrderTraverse(T->lchild,level+1);  /*�������T��������*/
       if(l != 0) return l;
        else
        return PreOrderTraverse(T->rchild,level+1) ;  /*�������T��������*/
        }
        return 0;
}

main()
{
   int level = 1;
   BiTree T = NULL;  /*�ʼTָ���*/
   CreatBiTree(&T);  /*����������*/
   /*�������������ҵ�����D�ַ����λ�ڶ������еĲ���*/
   printf("C is at level %d in the BITree\n",PreOrderTraverse(T,level) ) ;
   getche();
}
