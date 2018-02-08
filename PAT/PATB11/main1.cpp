#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int T,t=1;
	scanf("%d",&T);
	while(T--) {
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a+b>c) {
			printf("Case #%d: true\n",t++);
		} else {
			printf("Case #%d: false\n",t++);
		}
	}
	return 0;
}

