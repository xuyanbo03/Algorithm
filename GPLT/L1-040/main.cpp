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
	double h;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>c>>h;
		if(c=='M'){
			h=h/1.09;
			printf("%.2f\n",h);
		}
		if(c=='F'){
			h=h*1.09;
			printf("%.2f\n",h);
		}
	}
	return 0;
}

