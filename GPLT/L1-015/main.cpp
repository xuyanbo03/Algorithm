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
	char c;
	cin>>n>>c;
	int nb=n/2+n%2;
	for(int i=0;i<nb-1;i++){
		for(int j=0;j<n;j++){
			cout<<c;
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++){
		cout<<c;
	}
	return 0;
}

