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
const int maxn=10010;
int a[maxn][maxn],b[maxn][maxn],res[maxn][maxn]= {{0}};
int main() {
	int ra,ca,rb,cb,resr,resc;
	cin>>ra>>ca;
	for(int i=0; i<ra; i++) {
		for(int j=0; j<ca; j++) {
			cin>>a[i][j];
		}
	}
	cin>>rb>>cb;
	if(ca!=rb) {
		cout<<"Error: "<<ca<<" != "<<rb<<endl;
		return 0;
	}
	for(int i=0; i<rb; i++) {
		for(int j=0; j<cb; j++) {
			cin>>b[i][j];
		}
	}
	resr=ra;
	resc=cb;
	for(int i=0; i<resr; i++) {
		for(int j=0; j<resc; j++) {
			int sum=0;
			for(int k=0; k<ca; k++) {
				sum+=(a[i][k]*b[k][j]);
			}
			res[i][j]=sum;
		}
	}
	cout<<resr<<" "<<resc<<endl;
	for(int i=0; i<resr; i++) {
		for(int j=0; j<resc; j++) {
			if(j==resc-1) {
				cout<<res[i][j];
			} else {
				cout<<res[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}

