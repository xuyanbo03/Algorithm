#include "stdio.h"

typedef struct BiTNode{
    char data;   /*����������*/
    struct BiTNode *lchild , *rchild;  /*ָ�����Ӻ��Һ���*/
} BiTNode , *BiTree;

/*����һ�ö�����*/
CreatBiTree(BiTree *T , int *level1 , int level2){
    char c;

    scanf("%c",&c);
    if(c == ' ') *T = NULL;
    else{
       *T = (BiTNode * )malloc(sizeof(BiTNode));           /*���������*/
        (*T)->data = c;                                    /*����������������*/


        if(*level1<level2) {*level1 = level2;}


        CreatBiTree(&((*T)->lchild),&(*level1),level2+1);     /*�ݹ�ش���������*/
        CreatBiTree(&((*T)->rchild),&(*level1),level2+1);     /*�ݹ�ش���������*/
    }
}


int JusticCompleteBiTree(BiTree T,int level ,int n,int flag){
    if(!T){
        return 1;
        }
    if(level == n)
    {

       if(T->lchild == NULL && T->rchild != NULL) return 0;

       if(flag == 0){/*ͬ���ǰ��Ľ���޿�ָ��*/
            if(T->rchild == NULL) flag = 1; /*���ֿ�ָ��*/
            }
            else if(flag == 1){  /*ͬ���ǰ��Ľ���п�ָ��*/
                if(T->lchild!=NULL || T->rchild!=NULL)  return 0;
            }
    }
     if(level != n &&level !=n+1)
     {
        if(T->lchild == NULL || T->rchild == NULL) return 0;
     }
    if(!JusticCompleteBiTree(T->lchild,level+1,n,flag)) return 0;
    if(!JusticCompleteBiTree(T->rchild,level+1,n,flag)) return 0;
    return 1;
}


main()
{
    BiTree T;
    int level1 = 0;
    printf("Please type some character to creat a binary tree\n");
    CreatBiTree(&T, &level1,0);
    if(JusticCompleteBiTree(T,0,level1-1,0))  printf("It is a complete binary tree\n");
    else  printf("It is NOT a complete binary tree\n");
    getche();


}
