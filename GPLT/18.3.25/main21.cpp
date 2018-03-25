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
const int maxn=1e5;
double cs[maxn]={0};
int father[maxn];

int find(int x){
	while(x!=father[x]){
		x=father[x];
	}
	return x;
}
void uunion(int a,int b){
	int faa=find(a);
	int fab=find(b);
	if(faa!=fab){
		father[faa]=fab;
	}
}
int main(){
	int n,k,c;
	double z,r;
	for(int i=0;i<maxn;i++){
		father[i]=i;
	}
	cin>>n>>z>>r;
	r=r/100.0;
	cs[0]=z;
	ll res=0;
	double xz=z;
	for(int i=1;i<=n;i++){
		cin>>k;
		xz=xz-xz*r;
		if(k==0){
			int bs;
			cin>>bs;
			res+=(bs*xz);
			continue;
		}
		for(int j=0;j<k;j++){
			cin>>c;
			uunion(i,c);
		}
	}
	cout<<res;
	return 0;
}
