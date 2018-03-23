#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<sstream>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;
const int maxn=51;
set<int> s[maxn];

void cmp(int x,int y){
	int tNum=s[y].size();
	int sameNum=0;
	for(set<int>::iterator it=s[x].begin();it!=s[x].end();it++){
		if(s[y].find(*it)!=s[y].end()){
			sameNum++;
		}else{
			tNum++;
		}
	}
	printf("%.2f%%\n",sameNum*100.0/tNum);
}

int main(){
	int n,m,q,v,s1,s2;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m;
		for(int j=0;j<m;j++){
			cin>>v;
			s[i].insert(v);
		}
	}
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>s1>>s2;
		cmp(s1,s2);
	}
	return 0;
}

