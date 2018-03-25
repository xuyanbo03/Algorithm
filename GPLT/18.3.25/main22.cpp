#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1e18;
const int inf=0x3f3f3f3f;
const int maxn=1001;
struct people{
	int id,k;
	int n[maxn];
	double p[maxn];
	double sum=0;
}pp[maxn];
bool cmpn(people a,people b){
	return a.sum>b.sum;
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=maxn;i++){
		pp[i].id=i;
	}
	for(int i=1;i<=n;i++){
		int count=0,step;
		cin>>step;
		for(int j=0;j<step;j++){
			int a,b;
			cin>>a>>b;
			pp[a].sum+=b;
			count+=b;
		}
		pp[i].sum-=count;
	}
	sort(pp+1,pp+n+1,cmpn);
	for(int i=1;i<=n;i++){
		printf("%d %.2f\n",pp[i].id,pp[i].sum/100);
	}
	return 0;
}
