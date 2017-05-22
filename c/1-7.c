#include "stdio.h"

typedef struct ArcNode{
/*�������еĽ�������*/
int  adjvex;                /*�ñ�ָ��Ķ�����˳����е�λ��*/
struct ArcNode  *next;        /*��һ����*/
}ArcNode;

typedef struct VNode{
/*��������*/
int  data;            /*�����е�������Ϣ*/
ArcNode  *firstarc;            /*ָ��������ָ���һ����*/
}VNode;

int visited[5]={0,0,0,0,0};

CreatGraph(int n , VNode G[] ){
   int i,e;
   ArcNode *p , *q;
   printf("Input the information of the vertex\n");
   for(i=0;i<n;i++){
       scanf("%d",&G[i]);
       G[i].firstarc = NULL;                        /*��ʼ����һ����Ϊ��*/
       }
   for(i=0;i<n;i++){
   printf("Creat the edges for the %dth vertex\n",i) ;
   scanf("%d",&e);
    while(e!=-1){
      p = (ArcNode *)malloc(sizeof(ArcNode));            /*����һ����*/
      p->next = NULL;
      p->adjvex = e;
      if(G[i].firstarc == NULL) G[i].firstarc = p;        /*i���ĵ�һ����*/
      else q->next = p;                            /*��һ����*/
      q = p;
      scanf("%d",&e);
      }
   }
}

int  FirstAdj(VNode G[],int v){
if(G[v].firstarc != NULL)  return (G[v].firstarc)->adjvex;
    return -1;
}

int  NextAdj(VNode G[],int v){
     ArcNode *p;
     p = G[v].firstarc;
     while( p!= NULL){
        if(visited[p->adjvex]) p = p->next;
        else return p->adjvex;
     }
     return -1;
}

void DFS(VNode G[],int v){
    int w;
   printf("%d ",G[v]);     /*���ʵ�ǰ����,��ӡ���ö����е�������Ϣ*/
    visited[v] = 1;         /*������v��Ӧ�ķ��ʱ����1*/
    w = FirstAdj(G,v);      /*�ҵ�����v�ĵ�һ���ڽӵ㣬������ڽӵ㣬����-1*/
    while(w != -1){
    if(visited[w] == 0)        /*�ö���δ������*/
            DFS(G,w);                /*�ݹ�ؽ��������������*/
    w = NextAdj(G,v);        /*�ҵ�����v����һ���ڽӵ㣬������ڽӵ㣬����-1*/
    }
}

main()
{
    VNode G[5];
    CreatGraph(5,G);
    DFS(G,0);
    getche();
}

