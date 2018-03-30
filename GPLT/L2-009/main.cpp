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
struct node{
	int id,total,getnum;
};
bool cmp(node a,node b){
	if(a.total!=b.total){
		return a.total>b.total;
	}else if(a.getnum!=b.getnum){
		return a.getnum>b.getnum;
	}else {
		return a.id<b.id;
	}
}
int main(){
	int n,k,a,b;
	scanf("%d",&n);
	vector<node> v(n+1);
	for(int i=1;i<=n;i++){
		v[i].id=i;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d %d",&a,&b);
			v[a].total+=b;
			v[a].getnum++;
			v[i].total-=b;
		} 
	}
	sort(v.begin()+1,v.end(),cmp);
	for(int i=1;i<=n;i++){
		double tmp=(double)(v[i].total*1.0/100);
		printf("%d %.2f\n",v[i].id,tmp);
	}
	return 0;
}

