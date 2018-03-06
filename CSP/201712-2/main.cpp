#include<iostream>
#include<cstdio>
#include<queue>
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	queue<int> q;
	for(int i=1; i<=n; i++) {
		q.push(i);
	}
	int u=1;
	int t=1;
	while(!q.empty()) {
		u=q.front();
		q.pop();
		if(t%k==0||t%10==k) {
			;
		}else{
			q.push(u);
		}
		t++;
	}
	printf("%d",u);
	return 0;
}

