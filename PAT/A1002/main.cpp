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
const int maxn=1111;
double p[maxn]={0};

int main(){
	int k,n,count=0;
	double a;
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>n>>a;
		p[n]+=a;
	}
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>n>>a;
		p[n]+=a;
	}
	for(int i=0;i<maxn;i++){
		if(p[i]!=0){
			count++;
		}
	}
	cout<<count;
	for(int i=maxn-1;i>=0;i--){
		if(p[i]!=0){
			printf(" %d %.1f",i,p[i]);
		}
	}
	return 0;
}

