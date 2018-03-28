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
const ll maxn=2147483647;

void selectPrime(int n){
	if(n<2){
		return;
	}
	const bool exist=true;
	const bool notExist=false;
	bool* A=new bool[n+1];
	memset(A,exist,sizeof(bool)*(n+1));
	for(int p=2;p*p<=n;p++){
		if(A[p]==exist){
			int j=p*p;
			while(j<=n){
				A[j]=notExist;
				j+=p;
			}
		}
	}
	delete[] A;
}

bool isPrime(int a){
	if(a==1){
		return false;
	}
	for(int i=2;i<=sqrt(a);i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		if(isPrime(tmp)){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	return 0;
}

