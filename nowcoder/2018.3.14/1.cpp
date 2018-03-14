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
const int maxn=1e5+10;
const int maxm=1e4+10;
const int inf=0x3f3f3f3f;
const int mod=998244353;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;

//int n,s;
//int p[11];
//int ans=0;
//int sum=0;
//void dfs(int index,int sum,int ans){
//	if(sum==s&&index==n){
//		return;
//	}else{
//		dfs(index+1,sum+p[index],ans++);
//		dfs(index+1,sum,ans);
//	}
//	return;
//}
//
//int main(){
//	cin>>n>>s;
//	if(n>10||n<1||s>1000||s<1){
//		return 1;
//	}
//	for(int i=0;i<n;i++){
//		cin>>p[i];
//	}
//	dfs(0,sum,ans);
//	cout<<ans;
//	return 0;
//}


int main(){
	int n,s;
	int p[11];
	cin>>n>>s;
    if(n>10||n<1||s>1000||s<1){
		return 1;
	}
	for(int i=0;i<n;i++){
		cin>>p[i];
	}
	sort(p,p+n);
	int ans=0;
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=p[i];
		ans++;
		if(sum>=s){
			break;
		}
	}
	for(int i=0;sum>s&&i<n;i++){
		if(sum-p[i]>s){
			sum-=p[i];
			ans--;
			continue;
		}else{
			break;
		}
	}
	cout<<ans;
	return 0;
}
