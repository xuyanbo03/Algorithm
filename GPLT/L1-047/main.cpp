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
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		int hx,mb;
		cin>>s>>hx>>mb;
		if(hx<15||hx>20||mb<50||mb>70){
			cout<<s<<endl;
		}
	}
	return 0;
}

