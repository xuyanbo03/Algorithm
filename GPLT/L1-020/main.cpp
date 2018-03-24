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
	set<string> s,ans;
	string str;
	int n,k,m,flag=0;
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>k;
		if(k>=2) {
			for(int j=0; j<k; j++) {
				cin>>str;
				s.insert(str);
			}
		}else {
			cin>>str;
		}
	}
	cin>>m;
	for(int i=0; i<m; i++) {
		cin>>str;
		if(s.find(str)==s.end()&&ans.find(str)==ans.end()){
			ans.insert(str);
			if(flag==1){
				cout<<" ";
			}
			cout<<str;
			flag=1;
		}
	}
	if(flag==0) {
		cout<<"No one is handsome";
	}
	return 0;
}

