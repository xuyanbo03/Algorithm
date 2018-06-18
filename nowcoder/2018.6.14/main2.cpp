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

struct tc{
	int x;
	int y;
	double dj;
}a[1005];

int cmpp(tc a1,tc a2){
	if(a1.dj<=a2.dj){
		return true;
	}else{
		return false;
	}
}

int main(){
	int n,m,k,t1,t2;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d %d",&t1,&t2);
		a[i].x=t1;
		a[i].y=t2; 
		a[i].dj=(double)t1/t2;
	}
	sort(a,a+m,cmpp);
	int people=n+1;
	int money=0;
	while(1){
		if(people>=a[0].y){
			money+=a[0].x;
			people-=a[0].y;
		}else{
			break;
		}
	}
	for(int i=1;i<m;i++){
		if(a[i].dj>=k){
			break;
		}
		if(people>=a[i].y){
			money+=a[i].x;
			people-=a[i].y;
		}
	}
	if(people!=0){
		money+=k;
		people--;
	}
	printf("%d\n",money);
	return 0;
}

//�������� 

//��Ŀ����
//��������籭Ҫ��ʼ����ţţ��Ϊһ�����ԣ���Ȼ����Ź�ȥ��Ļʽ�ֳ��Ļ��ᡣ����ţţһ����ȥ�־���̫����į���������������n��С�������һ��ȥĪ˹��(һ��n+1��)����ţţ��ʼ����Ļʽ����Ʊʱ��������Ʊ��m���ײͣ�ÿ���ײ���Ҫ����xԪ������y����Ʊ��ÿ����ƱҲ���Ե������򣬴�ʱ������Ʊ�ļ۸�ΪkԪ������ţţҪ����ѡ������Ʊ��ʹ�������ѵ�Ǯ���١�(ÿ���ײͿ��Թ������û������)��
//��������:
//��һ��������������n(0��n��999)��m(1��m��1000)��k(1��k��100000)
//������m�У�ÿ��������������xi(1��xi��100000)��yi(2��yi��1000), ��ʾ�ײ͵ļ۸���ײ��ڰ�������Ʊ������
//�������:
//���ţţ����Ҫ���ѵ�Ǯ��������
//ʾ��1
//����
//2 2 5
//6 2
//13 3
//���
//11
