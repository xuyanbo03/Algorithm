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
const int maxn=100;
struct problem{
	string name;
	int x;
	int y;
	double rate;
	int level;
}node[maxn];

bool cmp(problem a,problem b){
	return a.name<b.name;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>node[i].name>>node[i].x>>node[i].y;
		node[i].rate=(double)node[i].y/node[i].x;
		if(node[i].rate>=0.0&&node[i].rate<=0.3){
			node[i].level=5;
		}else if(node[i].rate>0.3&&node[i].rate<=0.6){
			node[i].level=4;
		}else if(node[i].rate>0.6&&node[i].rate<=1.0){
			node[i].level=3;
		}
	}
	sort(node,node+n,cmp);
	for(int i=0;i<n;i++){
		cout<<node[i].name<<" "<<node[i].level<<endl;
	}
	return 0;
}

