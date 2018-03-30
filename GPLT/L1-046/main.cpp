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

int main(){
	int n;
	char str[1001];
	cin>>n;
	int p=0;
	int now=1;
	int len=0;
	while(1){
		if(p||now/n){
			str[p++]='0'+now/n;
		}
		len++;
		now%=n;
		if(now==0){
			str[p]=0;
			cout<<str<<" "<<len<<endl;
			break;
		}
		now=now*10+1;
	}
	return 0;
}


//15·Ö 
//int main(){
//	int x,count=1;
//	ll res;
//	scanf("%d",&x);
//	for(ll i=1;i<INF;i=i*10+1,count++){
//		if(i%x==0){
//			res=i/x;
//			break;
//		}
//	}
//	printf("%lld %d",res,count);
//	return 0;
//}

