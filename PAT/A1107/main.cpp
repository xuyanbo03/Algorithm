#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010;
int father[maxn];
int isRoot[maxn]={0};
int course[maxn]={0};

void init(int n){
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
}

int findFather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	}
}

void uunion(int a,int b){
	int faa=findFather(a);
	int fab=findFather(b);
	if(faa!=fab){
		father[faa]=fab;
	}
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
	int n,k,h;
	scanf("%d",&n);
	init(n);
	for(int i=1;i<=n;i++){
		scanf("%d:",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&h);
			if(course[h]==0){
				course[h]=i;
			}
			uunion(i,findFather(course[h]));
		}
	}
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(isRoot[i]!=0){
			ans++;
		}
	}
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+n+1,cmp);
	for(int i=1;i<=n;i++){
		printf("%d",isRoot[i]);
		if(i<ans){
			printf(" ");
		}
	}
	return 0;
}
