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
	int d;
	cin>>d;
	if(d+2>7){
		d=d+2-7;
	}else {
		d=d+2;
	}
	cout<<d;
	return 0;
}

