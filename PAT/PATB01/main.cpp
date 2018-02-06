#include<iostream>
#include<cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	int step=0;
	while(n!=1) {
		if(n%2==1) {
			n=(3*n+1)/2;
		} else {
			n=n/2;
		}
		step++;
	}
	printf("%d",step);
	return 0;
}
