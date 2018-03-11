#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int max=sqrt(n);
	for(int len=12;len>=1;len--){
		for(int start=2;start<=max;start++){
			long long int ans=1;
			for(int i=start;i-start<=len-1;i++){
				ans*=i;
			}
			if(n%ans==0){
				cout<<len<<endl;
				cout<<start;
				for(int i=start+1;i-start<=len-1;i++){
					cout<<"*"<<i;
				}
				return 0;
			}
		}
	}
	cout<<"1"<<endl;
	cout<<n;
	return 0;
}

