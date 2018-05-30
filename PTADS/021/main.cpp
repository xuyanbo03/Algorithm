#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print( List L ); /* ϸ���ڴ˲������������NULL */

List Merge( List L1, List L2 );

int main()
{
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge( List L1, List L2 ){
	if(!L1&&!L2){
		return NULL;
	}
	List L,p1,p2,p;
	L=(List)malloc(sizeof(struct Node));
	p1=L1->Next;
	p2=L2->Next;
	p=L;
	while(pa&&pb){
		if(pa->Data<=pb->Data){
			p->Next=p1;
			p1=p1->Next;
		}else{
			p->Next=p2;
			p2=p2->Next;
		}
		p=p->Next; 
	}
	if(p1){
		p->Next=p1;
	}
	if(p2){
		p->Next=p2;
	}
	L1->Next=NULL;
	L2->Next=NULL;
	return L;
}


//02-���Խṹ1 ���������������еĺϲ���15 �֣�
//����Ҫ��ʵ��һ�������������������ʾ�ĵ����������кϲ�Ϊһ���ǵݼ����������С�
//
//�����ӿڶ��壺
//List Merge( List L1, List L2 );
//����List�ṹ�������£�
//
//typedef struct Node *PtrToNode;
//struct Node {
//    ElementType Data; /* �洢������� */
//    PtrToNode   Next; /* ָ����һ������ָ�� */
//};
//typedef PtrToNode List; /* ���嵥�������� */
//L1��L2�Ǹ����Ĵ�ͷ���ĵ���������洢�������ǵ�������ģ�����MergeҪ��L1��L2�ϲ�Ϊһ���ǵݼ����������С�Ӧֱ��ʹ��ԭ�����еĽ�㣬���ع鲢��Ĵ�ͷ��������ͷָ�롣
//
//���в��Գ���������
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef int ElementType;
//typedef struct Node *PtrToNode;
//struct Node {
//    ElementType Data;
//    PtrToNode   Next;
//};
//typedef PtrToNode List;
//
//List Read(); /* ϸ���ڴ˲��� */
//void Print( List L ); /* ϸ���ڴ˲������������NULL */
//
//List Merge( List L1, List L2 );
//
//int main()
//{
//    List L1, L2, L;
//    L1 = Read();
//    L2 = Read();
//    L = Merge(L1, L2);
//    Print(L);
//    Print(L1);
//    Print(L2);
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//����������
//3
//1 3 5
//5
//2 4 6 8 10
//���������
//1 2 3 4 5 6 8 10 
//NULL
//NULL
