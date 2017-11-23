#include <iostream>
#include <cstdio>
#define ll long long
using namespace std;

//ll gcd(ll x,ll y){
//	return x==0?y:gcd(y%x,x);
//}
//
//ll lcmm(ll x,ll y){
//	return (x*y/gcd(x,y));
//}

ll lcm(ll x,ll y){
	ll c,d,e;
	c=x;
	d=y;
	e=c%d;
	while(e){
		c=d;
		d=e;
		e=c%d;
	}
	return (x*y/d);
}

int main(){
	ll a,b;
	//cin>>a>>b;
	while(~scanf("%lld %lld",&a,&b)){
		cout<<lcm(a,b)<<endl;	
	}
	return 0;
}
