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

struct yls{
	ll up,down;
};

ll gcd(ll a,ll b){
	return !b?a:gcd(b,a%b);
}

yls reduction(yls res){
	if(res.down<0){
		res.up=-res.up;
		res.down=-res.down;
	}
	if(res.up==0){
		res.down=1;
	}else{
		int d=gcd(abs(res.up),abs(res.down));
		res.up/=d;
		res.down/=d;
	}
	return res;
}

yls add(yls f1,yls f2){
	yls res;
	res.up=f1.up*f2.down+f2.up*f1.down;
	res.down=f1.down*f2.down;
	return reduction(res);
}

void show(yls r){
	r=reduction(r);
	if(r.down==1){
		printf("%lld",r.up);
	}else if(abs(r.up)>r.down){
		printf("%lld %lld/%lld",r.up/r.down,abs(r.up)%r.down,r.down);
	}else{
		printf("%lld/%lld",r.up,r.down);
	}
}

int main(){
	ll n;
	scanf("%lld",&n);
	yls sum;
	sum.up=0;
	sum.down=1;
	for(int i=0;i<n;i++){
		yls a;
		scanf("%lld/%lld",&a.up,&a.down);
		sum=reduction(add(sum,a));
	}
	show(sum);
	return 0;
}

