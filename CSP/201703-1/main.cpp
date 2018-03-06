#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1000;
int a[maxn];
int main() {
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	int p=0;
	int count=0;
	for(int i=0;i<n;i++) {
		count+=a[i];
		if(count>=k){
			p++;
			count=0;
		}
	}
	if(count>0){
		p++;
	}
	printf("%d",p);
	return 0;
}

