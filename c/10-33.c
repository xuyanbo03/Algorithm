#include <string.h> 
#include <stdio.h> 

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

/*�������������õ�Ҷ���ĸ���*/
getLeaves(BiTree T,int *count){
    if(T->lchild==NULL && T->rchild==NULL && T!=NULL){   /*���ʵ�Ҷ���*/
        *count = *count + 1;
    }
    if(T){
        getLeaves(T->lchild,count);  /*�������T��������*/
        getLeaves(T->rchild,count);  /*�������T��������*/
    }
}

main()
{
   int count = 0;
   BiTree T = NULL;			/*�ʼTָ���*/
   CreatBiTree(&T);			/*����������*/
   getLeaves(T,&count); 		/*�������������õ�Ҷ���ĸ�������count����Ҷ���ĸ���*/
   printf("The number of leaves of BTree are %d\n",count);
   getche();
}
