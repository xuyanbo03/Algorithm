#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1000;
int a[maxn];
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++) {
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	int mid=n/2;
	int l=mid;
	int r=n-mid-1;
	for(int i=mid-1; i>=0; i--) {
		if(a[i]==a[mid]) {
			l--;
		} else {
			break;
		}
	}
	for(int i=mid+1; i<n; i++) {
		if(a[i]==a[mid]) {
			r--;
		} else {
			break;
		}
	}
	if(l==r) {
		printf("%d",a[mid]);
	} else {
		printf("-1");
	}
	return 0;
}

