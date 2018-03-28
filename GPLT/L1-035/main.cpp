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
	string s,a,b;
	int cnt=0;
	while(cin>>s){
		if(s=="."){
			break;
		}
		cnt++;
		if(cnt==2){
			a=s;
		}
		if(cnt==14){
			b=s;
		}
	}
	if(cnt<=1){
		cout<<"Momo... No one is for you ..."<<endl;
	}else if(cnt>=14){
		cout<<a<<" and "<<b<<" are inviting you to dinner..."<<endl;
	}else {
		cout<<a<<" is the only one for you..."<<endl;
	}
	return 0;
}
