#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int n;
	scanf("%d",&n);
	int c=0;
	while(n>0) {
		if(n-50>=0) {
			c+=7;
			n-=50;
		} else if(n-30>=0) {
			c+=4;
			n-=30;
		} else {
			c++;
			n-=10;
		}
	}
	printf("%d",c);
	return 0;
}

