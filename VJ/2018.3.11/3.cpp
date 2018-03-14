#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int c;
	cin>>c;
	while(c--) {
		int n,count=0;
		cin>>n;
		while(n!=0) {
			if(n%2==0) {
				n=n/2;
			} else {
				n=n-1;
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}

