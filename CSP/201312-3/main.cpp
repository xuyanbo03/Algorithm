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
	vector<int> a;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	int ans=0;
	for(int i=0;i<n;i++){
		int h=a[i];
		for(int j=i;j<n;j++){
			if(a[j]<h){
				h=a[j];
			}
			int s=(j-i+1)*h;
			if(ans<s){
				ans=s;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

