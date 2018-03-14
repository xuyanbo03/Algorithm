#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
const int maxn=10010;
const int maxm=1e4+10;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;

struct zb{
	int ri1,ri2,ri3,ri4,ri5;
};
zb r[maxn];
int main(){
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>r[i].ri1>>r[i].ri2>>r[i].ri3>>r[i].ri4>>r[i].ri5;
	}
	int maxx=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int sum=0;
			for(int k=0;k<5;k++){
				sum+=max(r[i][k],r[j][k]);
			}
			maxx=sum;
		}
	}
	cout<<maxx;
	return 0;
}

