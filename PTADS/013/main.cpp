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


#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
Position BinarySearch( List L, ElementType X ){
	int start,end,mid;
	start=1;
	end=L->Last;
	mid=(start+end)/2;
	
	for(int i=L->Last;i>0;i=i/2){
		mid=(start+end)/2;
		if(L->Data[mid]==X){
			return mid;
			break;
		}else if(L->Data[mid]>X){
			end=mid-1;
		}else if(L->Data[mid]<X){
			start=mid+1;
		}
	}
	return NotFound;
}


//01-���Ӷ�3 ���ֲ��ң�20 �֣�
//����Ҫ��ʵ�ֶ��ֲ����㷨��
//
//�����ӿڶ��壺
//Position BinarySearch( List L, ElementType X );
//����List�ṹ�������£�
//
//typedef int Position;
//typedef struct LNode *List;
//struct LNode {
//    ElementType Data[MAXSIZE];
//    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
//};
//L���û������һ�����Ա�����ElementTypeԪ�ؿ���ͨ��>��==��<���бȽϣ�������Ŀ��֤����������ǵ�������ġ�����BinarySearchҪ����X��Data�е�λ�ã��������±꣨ע�⣺Ԫ�ش��±�1��ʼ�洢�����ҵ��򷵻��±꣬���򷵻�һ�������ʧ�ܱ��NotFound��
//
//���в��Գ���������
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXSIZE 10
//#define NotFound 0
//typedef int ElementType;
//
//typedef int Position;
//typedef struct LNode *List;
//struct LNode {
//    ElementType Data[MAXSIZE];
//    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
//};
//
//List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
//Position BinarySearch( List L, ElementType X );
//
//int main()
//{
//    List L;
//    ElementType X;
//    Position P;
//
//    L = ReadInput();
//    scanf("%d", &X);
//    P = BinarySearch( L, X );
//    printf("%d\n", P);
//
//    return 0;
//}
//
///* ��Ĵ��뽫��Ƕ������ */
//��������1��
//5
//12 31 55 89 101
//31
//�������1��
//2
//��������2��
//3
//26 78 233
//31
//�������2��
//0

