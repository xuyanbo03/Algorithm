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
const int maxn=100010;
int main(){
	int n,t;
	cin>>n;
	set<int> s;
	s.insert(0);
	for(int i=0;i<n;i++){
		cin>>t;
		if(t<*s.rbegin()){
			s.erase(*(s.upper_bound(t)));
		}
		s.insert(t);
	}
	cout<<s.size()-1;
	return 0;
}

