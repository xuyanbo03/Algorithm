#include<bits/stdc++.h>
using namespace std;

struct node {
	int id;
	int sta;
	int time;
	bool operator < (const node &u) const {
		if(time>u.time){
			return true;
		}
		if(time<u.time){
			return false;
		}
		if(sta>u.sta){
			return true;
		}
		if(sta<u.sta){
			return false;
		}
		if(id>u.id){
			return true;
		}
		return false;
	}
};
int a[1010];
priority_queue<node> pq;

int main() {
	memset(a,0,sizeof(a));
	int n,k,w,s,c;
	node x;
	scanf("%d%d",&n,&k);
	while(k--) {
		scanf("%d%d%d",&w,&s,&c);
		x.id=w;
		x.sta=1;
		x.time=s;
		pq.push(x);
		x.id=w;
		x.sta=0;
		x.time=s+c;
		pq.push(x);
	}
	for(int i=1; i<=n; i++) {
		a[i]=i;
	}

	while(!pq.empty()) {
		x=pq.top();
		pq.pop();
		if(x.sta==0) {
			for(int i=1; i<=n; i++) {
				if(a[i]==-1) {
					a[i]=x.id;
					break;
				}
			}
		} else {
			for(int i=1; i<=n; i++) {
				if(a[i]==x.id) {
					a[i]=-1;
					break;
				}
			}
		}
	}
	for(int i=1; i<n; i++) {
		printf("%d ",a[i]);
	}
	printf("%d",a[n]);
	return 0;
}
