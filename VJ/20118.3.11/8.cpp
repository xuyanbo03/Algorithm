#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

bool isprime(int x){
	for(int i=2;i<sqrt(x);i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}

long long int f(int n){
	if(n==1){
		return 1;
	}else if(isprime(n)){
		long long int sum=1;
		for(int i=1;i<n;i++){
			sum=(sum*2)%n;
		}
		return sum;
	}else {
		return (n-1)*(n-1)%n;
	}
}

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		cout<<"Case #"<<i<<": "<<f(n)<<endl;
	}
	return 0;
}

