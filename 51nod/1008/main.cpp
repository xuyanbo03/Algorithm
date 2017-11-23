#include <iostream>
#include <cstdio>
using namespace std;

#define ll long long 

int main(){
	ll i,ans;
	ll n,m;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		ans=1;
		for(i=n;i>0;i--){
			ans=ans*i;
			ans%=m;	
		}
		cout<<ans<<endl;
	}
	return 0;
}
