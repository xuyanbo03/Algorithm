#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=1010;
int main(){
	string s;
	cin>>s;
	int a,b,mid=0;
	int ans[21]={0};
	cin>>a>>b;
	for(int i=0;i<s.length();i++){
		int ga=a%10;
		a/=10;
		int gb=b%10;
		b/=10;
		ans[i]=ga+gb+mid;
		if(ans[i]>(int)s[s.length()-1-i]){
			ans[i]-=(int)s[s.length()-1-i];
			mid=1;
		}
	}
	for(int i=s.length()-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
}
