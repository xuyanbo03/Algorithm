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
	char c;
	cin>>n>>c;
	string s;
	getchar();
	getline(cin,s);
	int len=s.length();
	if(len<n){
		for(int i=0;i<n-len;i++){
			cout<<c;
		}
		for(int i=0;i<len;i++){
			cout<<s[i];
		}
	}else {
		for(int i=len-n;i<len;i++){
			cout<<s[i];
		}
	} 
	return 0;
}

