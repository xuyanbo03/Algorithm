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
int N=100010;

int MaxSubseqSum(int A[],int N){
	int ThisSum=0;
	int MaxSum=0;
	for(int i=0;i<N;i++){
		ThisSum+=A[i];
		if(ThisSum>MaxSum){
			MaxSum=ThisSum;
		}else if(ThisSum<0){
			ThisSum=0;
		}
	}
	return MaxSum;
}

int main(){
	int k;
	int a[N]={0};
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>a[i];
	}
	cout<<MaxSubseqSum(a,k)<<endl;
	return 0;
}

//01-���Ӷ�1 ������к����⣨20 �֣�
//����K��������ɵ����У����������С�������Ϊ������ 1��i��j��K����������к͡��򱻶���Ϊ������������Ԫ�صĺ�������ߡ������������{ -2, 11, -4, 13, -5, -2 }������������{ 11, -4, 13 }�����ĺ�20����Ҫ�����д���򣬼�������������е�������к͡�
//
//����ּ�ڲ��Ը��ֲ�ͬ���㷨�ڸ�����������µı��֡�������������ص����£�
//
//����1���������ȼۣ����Ի�����ȷ�ԣ�
//����2��102�����������
//����3��103�����������
//����4��104�����������
//����5��105�����������
//�����ʽ:
//�����1�и���������K (��100000)����2�и���K������������Կո�ָ���
//
//�����ʽ:
//��һ�������������к͡��������������������Ϊ�����������0��
//
//��������:
//6
//-2 11 -4 13 -5 -2
//�������:
//20
