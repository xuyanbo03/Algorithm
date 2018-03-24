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

vector<int> fri;
int enemy[101][101];
int find(int x){
	while(x!=fri[x]){
		x=fri[x];
	}
	return x;
}
void uunion(int a,int b){
	int fria=find(a);
	int frib=find(b);
	if(fria!=frib){
		fri[fria]=frib;
	}
}

int main(){
	int n,m,k,a,b,c;
	cin>>n>>m>>k;
	fri.resize(n+1);
	for(int i=1;i<=n;i++){
		fri[i]=i;
	} 
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		if(c==1){
			uunion(a,b);
		}else{
			enemy[a][b]=1;
			enemy[b][a]=1;
		}
	}
	for(int i=0;i<k;i++){
		cin>>a>>b;
		if(find(a)==find(b)&&enemy[a][b]==0){
			cout<<"No problem\n";
		}else if(find(a)!=find(b)&&enemy[a][b]==0){
			cout<<"OK\n";
		}else if(find(a)==find(b)&&enemy[a][b]==1){
			cout<<"OK but...\n";
		}else if(enemy[a][b]==1){
			cout<<"No way\n";
		}
	}
	return 0;
}

