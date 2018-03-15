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
const ll mod=1e9+7;

//ll f[2000][3][2];// f[seq_k to place][0: to place 0 , 1: ethier 0 or 1, 2 : must be 1][3 is placed ? 1 : 0]
//
//int dp(int n,int p1,int p3){
//	ll now=f[n][p1][p3];
//	if(now!=-1){
//		return now;
//	}
//	if(n==0){
//		if(p1==2&&p3==1){
//			now=1;
//		}else{
//			now=0;
//		}
//		return now;
//	}
//	now=0;
//	if(p1==0){
//		//go 0
//		now+=dp(n-1,1,p3);
//	}else if(p1==1){
//		//go 0
//		now+=dp(n-1,1,p3);
//		//go 1
//		now+=dp(n-1,2,p3);
//	}else{
//		//p1==2
//		//go 1
//		now+=dp(n-1,2,p3);
//	}
//	if(p3==0){
//		//go 2
//		now+=dp(n-1,p1,p3);
//		//go 3
//		now+=dp(n-1,p1,1);
//	}else{
//		//go 3
//		now+=dp(n-1,p1,1); 
//	}
//	now%=mod;
//}
//
//int main(){
//	int n;
//	cin>>n;
//	memset(f,-1,sizeof(f));
//	int ans=dp(n-1,0,0);
//	cout<<ans<<endl;
//	return 0;
//}


ll sta[1024][6],n;
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i)
    {
        sta[i][0]=1;
        sta[i][1]=(sta[i-1][0]+sta[i-1][1]*2)%mod;
        sta[i][2]=(sta[i-1][0]+sta[i-1][2])%mod;
        sta[i][3]=(sta[i-1][1]+sta[i-1][3]*2)%mod;
        sta[i][4]=(sta[i-1][1]+sta[i-1][2]+sta[i-1][4]*2)%mod;
        sta[i][5]=(sta[i-1][3]+sta[i-1][4]+sta[i-1][5]*2)%mod;
    }
    printf("%lld\n",sta[n][5]);
    return 0;
}
