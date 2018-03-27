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
	int n,t,odd=0,even=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>t;
		if(t%2==0){
			even++;
		}else{
			odd++;
		}
	}
	cout<<odd<<" "<<even;
	return 0;
}

