#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int n,m,count=0;
	cin>>n>>m;
	int i;
	for(i=2; i<=n; i=i+2) {
		for(int j=0; j<m; j++) {
			count++;
		}

	}
	if(i>n&&i-1==n) {
		for(int k=2; k<=m; k=k+2) {
			count++;
		}
	}
	cout<<count;
	return 0;
}

