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

int dis[maxn],maxtree,pre[maxn];
bool vis[maxn]={false};
vector<pair<int,int> > e[maxn];

int main(){
    fill(dis, dis + maxn, inf);
	int n,m;
	cin>>n>>m;
	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		e[a].push_back(make_pair(b,c));
	}
	dis[0]=0;
	maxtree=0;
	for(int i=0;i<n;i++){
		int u=-1,minn=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&dis[j]<minn){
				u=j;
				minn=dis[j];
			}
		}
		if(u==-1){
			break;
		}
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&e[u].size()>0){
				if(dis[u] + e[u][v].second < dis[v]) {
                    dis[v] = dis[u] + e[u][v].second;
                    pre[v] = u;
                    maxtree=max(maxtree,e[u][v].second);
                }
			}
		}
	}
	cout<<maxtree;
	return 0;
}

