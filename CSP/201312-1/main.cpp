#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	map<int,int> f;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		f[t]++;
	}
	int ans;
	int m=0;
	for(map<int,int>::iterator it=f.begin();it!=f.end();it++){
		if(it->second>m){
			m=it->second;
			ans=it->first;
		}
	}
	cout<<ans;
	return 0;
}
