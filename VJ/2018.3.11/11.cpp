#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

typedef long long ll;
const int maxn=100010;
int s[maxn];
int main() {
	int t;
	cin>>t;
	for(int i=0; i<t; i++) {
		int n,a;
		cin>>n>>a;
		for(int i=0; i<n; i++) {
			cin>>s[i];
		}
		int len=0;
		for(int i=0; i<n; i++) {
			for(int j=i+1; j<n; j++) {
				int mn=0,mx=0;
				if(j==i+1) {
					mn=min(s[i],s[j]);
					mx=max(s[j],s[i]);
				}
				mn=min(mn,s[j]);
				mx=max(mx,s[j]);
				ll f1=(2*a+mn)/(mx+a);
				ll f2=(mx-a)/(mn);
				if(f1>=f2) {
					len=max(len,j-i+1);
				}
			}
		}
		cout<<"Case #"<<t<<": "<<len;
	}
	return 0;
}

