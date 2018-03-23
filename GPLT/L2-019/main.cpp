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
const int maxn=5010;
const int maxm=10010;
int main(){
	int n,m,flag=0;
	string a,t;
	int b;
	cin>>n;
	set<string> s;
	map<string,int> mp;
	for(int i=0;i<n;i++){
		cin>>t;
		s.insert(t);
	}
	cin>>m;
	int sum=0;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		sum+=b;
		mp.insert(make_pair(a,b));
	}
	int avg=sum/m;
	for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
		if(it->second>avg&&s.find(it->first)==s.end()){
			cout<<it->first<<endl;
			flag=1;
		}
	}
	if(flag==0){
		cout<<"Bing Mei You";
	} 
	return 0;
}

