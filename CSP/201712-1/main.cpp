#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=1005;
const int inf=10001;
int a[maxn];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	int min=inf;
	for(int i=1; i<n; i++) {
		for(int j=i-1; j>=0; j--) {
			if(a[i]==a[j]) {
				min=0;
				break;
			}
			int d=abs(a[i]-a[j]);
			if(d<min){
				min=d;
			}
		}
	}
	printf("%d",min);
	return 0;
}

