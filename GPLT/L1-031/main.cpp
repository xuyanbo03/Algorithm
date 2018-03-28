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

int main() {
	int n;
	cin>>n;
	for(int i=0; i<n; i++) {
		int h,w;
		cin>>h>>w;
		double w1=(h-100)*0.9*2;
		double w2=w1*0.1;
		if(fabs(w-w1)<w2){
			cout<<"You are wan mei!"<<endl;
		}else if(w>w1){
			cout<<"You are tai pang le!"<<endl;
		}else if(w<w1){
			cout<<"You are tai shou le!"<<endl;
		}
	}
	return 0;
}

