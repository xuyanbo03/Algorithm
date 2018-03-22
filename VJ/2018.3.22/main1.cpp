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
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;
const int maxn=50;
vector<int> g[maxn];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int count=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			int du=g[i].size();
			int dv=g[j].size();
			if(du+dv>=n){
				if(g[i][j]==0){
					count+=2;
				}
			}
		}
	}
	cout<<count;
	return 0;
}

