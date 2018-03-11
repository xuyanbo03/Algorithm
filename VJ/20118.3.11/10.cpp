#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int n,m;
	long long int count=0;
	cin>>n>>m;
	string c[n];
	for(int i=0; i<n; i++) {
		cin>>c[i];
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(c[i][j]=='*') {
				int x=0,y=0;
				for(int k=i+1; k<n; k++) {
					if(c[k][j]=='*') {
						x++;
						continue;
					}
				}
				for(int l=j+1; j<m; j++) {
					if(c[i][l]=='*') {
						y++;
						continue;
					}
				}
				count+=x*y;
			}
		}
	}
	cout<<count;
	return 0;
}

