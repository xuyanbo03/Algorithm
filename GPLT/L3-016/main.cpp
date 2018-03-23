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

int num;
int tree[1<<20];
void bst(int a){
	if(tree[a]==0){
		tree[a]=num;
	}else if(tree[a]<0){
		bst(a<<1);
	}else{
		bst(a<<1|1);
	}
}

int main(){
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>num;
		bst(1);
	}
	cin>>m;
	string s;
	for(int i=0;i<m;i++){
		cin>>s;
	} 
	return 0;
}

