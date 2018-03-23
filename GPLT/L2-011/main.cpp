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

vector<int> pre,in,level(10000,-1);
void levelorder(int root,int start,int end,int index){
	if(start>end){
		return;
	}
	int i=start;
	while(i<end&&in[i]!=pre[root]){
		i++;
	}
	level[index]=pre[root];
	levelorder(root+1,start,i-1,2*index+2);
	levelorder(root+1+i-start,i+1,end,2*index+1);
}
int main(){
	int n,cnt=0;
	cin>>n;
	pre.resize(n);
	in.resize(n);
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	levelorder(0,0,n-1,0);
	for(int i=0;i<level.size();i++){
		if(level[i]!=-1&&cnt!=n-1){
			cout<<level[i]<<" ";
			cnt++;
		}else if(level[i]!=-1){
			cout<<level[i];
			break;
		}
	}
	return 0;
}

