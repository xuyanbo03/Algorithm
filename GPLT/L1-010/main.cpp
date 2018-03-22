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
	int a[3];
	for(int i=0;i<3;i++){
		cin>>a[i];
	}
	sort(a,a+3);
	for(int i=0;i<3;i++){
		if(i==2){
			cout<<a[i];
		}else{
			cout<<a[i]<<"->";
		}
	}
	return 0;
}

