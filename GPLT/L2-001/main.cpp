#include<bits/stdc++.h>
using namespace std;

const int maxv=510;
const int inf=1e9;
int n,m,st,ed,G[maxv][maxv],weight[maxv];
int d[maxv],w[maxv],num[maxv],pre[maxv];
bool vis[maxv]= {false};

void dijkstra(int s) {
	fill(d,d+maxv,inf);
	memset(num,0,sizeof(num));
	memset(w,0,sizeof(w));
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	for(int i=0; i<n; i++) {
		int u=-1,minn=inf;
		for(int j=0; j<n; j++) {
			if(vis[j]==false&&d[j]<minn) {
				u=j;
				minn=d[j];
			}
		}
		if(u==-1) {
			return;
		}
		vis[u]=true;
		for(int v=0; v<n; v++) {
			if(vis[v]==false&&G[u][v]!=inf) {
				if(d[u]+G[u][v]<d[v]) {
					d[v]=d[u]+G[u][v];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
					pre[v]=u;
				} else if(d[u]+G[u][v]==d[v]) {
					if(w[u]+weight[v]>w[v]) {
						w[v]=w[u]+weight[v];
						pre[v]=u;
					}
					num[v]+=num[u];
				}
			}
		}
	}
}

void printpath(int s) {
	if(s==st) {
		cout<<s;
		return;
	}
	printpath(pre[s]);
	cout<<" "<<s;
}

int main() {
	cin>>n>>m>>st>>ed;
	for(int i=0; i<n; i++) {
		cin>>weight[i];
	}
	int u,v,x;
	fill(G[0],G[0]+maxv*maxv,inf);
	for(int i=0; i<m; i++) {
		cin>>u>>v>>x;
		G[v][u]=x;
		G[u][v]=x;
	}
	dijkstra(st);
	cout<<num[ed]<<" "<<w[ed]<<endl;
	printpath(ed);
	return 0;
}

