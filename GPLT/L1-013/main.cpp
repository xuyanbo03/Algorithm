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

int main(){
	int n;
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++){
		int tmp=1;
		for(int j=1;j<=i;j++){
			tmp*=j;
		}
		sum+=tmp;
	}
	cout<<sum;
	return 0;
}

