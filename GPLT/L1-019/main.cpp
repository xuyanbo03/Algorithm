#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;
const int maxn=110;

int main(){
	int a,b,n;
	cin>>a>>b>>n;
	int ca=a;
	int cb=b;
	int jh,jc,yh,yc;
	for(int i=0;i<n;i++){
		cin>>jh>>jc>>yh>>yc;
		if(jh+yh==jc&&yh+jh!=yc){
			ca--;
		}
		if(jh+yh!=jc&&yh+jh==yc){
			cb--;
		}
		if(ca==-1){
			printf("A\n%d",b-cb);
			break;
		}
		if(cb==-1){
			printf("B\n%d",a-ca);
			break;
		}
	}
	return 0;
}

