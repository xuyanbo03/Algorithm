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

struct shop{
	int price;
	int flag;
}a[11];
struct mj{
	int man;
	int jian;
	int cha;
}b[11];

//bool cmpp(mj m1,mj m2){
//	if(m1.cha>m2.cha){
//		return m1.cha-m2.cha;
//	}else{
//		return m1.man-m2.cha;
//	}
//}

int main(){
	int n,m;
	int t1,t2;
	double sum1=0;
	double sum2=0;
	double res=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t1>>t2;
		a[i].price=t1;
		a[i].flag=t2;
	}
	for(int i=0;i<m;i++){
		cin>>t1>>t1;
		b[i].man=t1;
		b[i].jian=t2;
		b[i].cha=t1-t2;
	}
	//sort(b,b+m,cmpp);
	for(int i=0;i<n;i++){
		if(a[i].flag==1){
			sum1+=(a[i].price*0.8);
		}else{
			sum1+=a[i].price;
		}
	}
	for(int i=0;i<n;i++){
		sum2+=a[i].price;
	}
	int tsum=inf;
	for(int i=0;i<m;i++){
		if(sum2>b[i].man){
			if(tsum>(sum2-b[i].jian))
				tsum=sum2-b[i].jian;
		}
	}
	if(tsum<sum1){
		res=tsum;
	}else{
		res=sum1;
	}
	printf("%.2f",res);
	return 0;
}

