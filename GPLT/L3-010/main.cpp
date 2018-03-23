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

int tree[1<<20];
int num;
void bst(int a){
	if(tree[a]==0){
		tree[a]=num;
	}else if(tree[a]<num){
		bst(a<<1);
	}else{
		bst(a<<1|1);
	}
}

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&num);
		bst(1);
	}
	bool flag=true;
	for(int cnt=1,k=1;cnt<=n;k++){
		if(tree[k]==0){
			flag=false;
		}else{
			printf("%d",tree[k]);
			cnt++;
			if(cnt!=n+1){
				printf(" ");
			}
		}
	}
	if(flag){
		printf("\nYES");
	}else{
		printf("\nNO");
	}
	return 0;
}

