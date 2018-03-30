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

bool vis[510];
int e[510][510],n,m,k;
void dfs(int node){
	vis[node]=true;
	for(int i=0;i<n;i++){
		if(vis[i]==false&&e[node][i]==1){
			dfs(i);
		}
	}
}
int countcnt(){
	int cnt=0;
	fill(vis,vis+510,false);
	for(int i=0;i<n;i++){
		if(vis[i]==false){
			dfs(i);
			cnt++;
		}
	}
	return cnt;
}
int main(){
	cin>>n>>m;
	int a,b,c;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		e[a][b]=e[b][a]=1;
	}
	int cnt=countcnt();
	cin>>k;
	for(int i=0;i<k;i++){
		cin>>c;
		for(int j=0;j<n;j++){
			if(e[c][j]==1){
				e[c][j]=0;
				e[j][c]=0;
			}
		}
		int tmp=countcnt();
		if(tmp>cnt+1){
			cout<<"Red Alert: City "<<c<<" is lost!\n";
		}else{
			cout<<"City "<<c<<" is lost.\n";
		}
		cnt=tmp;
		if(i==n-1){
			cout<<"Game Over.\n";
		}
	}
	return 0;
}

