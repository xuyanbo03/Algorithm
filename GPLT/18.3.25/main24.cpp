#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=100010;
bool exist[maxn]= {false};
struct NODE {
	int address;
	int key;
	int next;
	int num;
} node[maxn];

int cmpn(NODE a,NODE b) {
	return a.num<b.num;
}

int main() {
	int first,n,c1=0,c2=0,add;
	scanf("%d%d",&first,&n);
	for(int i=0; i<maxn; i++) {
		node[i].num=2*maxn;
	}
	for(int i=0; i<n; i++) {
		scanf("%d",&add);
		scanf("%d%d",&node[add].key,&node[add].next);
		node[add].address=add;
	}
	for(int i=first; i!=-1; i=node[i].next) {
		if(exist[abs(node[i].key)]==false) {
			exist[abs(node[i].key)]=true;
			node[i].num=c1;
			c1++;
		} else {
			node[i].num=maxn+c2;
			c2++;
		}
	}
	sort(node,node+maxn,cmpn);
	int c=c1+c2;
	for(int i=0; i<c; i++) {
		if(i!=c1-1&&i!=c-1) {
			printf("%05d %d %05d\n",node[i].address,node[i].key,node[i+1].address);
		} else {
			printf("%05d %d -1\n",node[i].address,node[i].key);
		}
	}
	return 0;
}

