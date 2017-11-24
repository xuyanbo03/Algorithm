#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define N 1000
using namespace std;

int main() {
	int n,k,m;
	vector<int> v[N];
	int a;
	cin>>n>>k>>m;
	
	for(int i=0; i<n; i++) {
		cin>>a;
		v[a%m].push_back(a);
		if(v[a%m].size()==k) {
			cout<<"Yes"<<endl;
			for(int j=0; j<v[a%m].size(); j++) {
				cout<<v[a%m][j]<<" ";
			}
			cout<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;
}
