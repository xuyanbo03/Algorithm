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

map<int,char> a;
map<int,int> b;
int main() {
	int n;
	scanf("%d",&n);
	while(n--) {
		double time=0.0;
		int sum=0;
		a.clear();
		b.clear();
		int id,h,m;
		char flag;
		while(scanf("%d %c %d:%d",&id,&flag,&h,&m)) {
			if(id==0) {
				break;
			}
			if(flag=='S') {
				a[id]='S';
				b[id]=h*60+m;
			}
			if(flag=='E') {
				if(a[id]=='S') {
					time+=h*60+m-b[id];
					sum++;
					a[id]='0';
				}
			}
		}
		if(sum!=0) {
			time/=sum;
		}
		int t=time+0.5;
		printf("%d %d\n",sum,t);
	}
	return 0;
}

