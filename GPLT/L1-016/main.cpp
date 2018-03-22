#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;

int main() {
	int b[]= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int m[]={1,0,10,9,8,7,6,5,4,3,2};
	int a[18];
	int n,count=0;
	cin>>n;
	while(n--) {
		bool flag=false;
		string s;
		cin>>s;
		int sum=0;
		for(int i=0; i<17; i++) {
			if(!isdigit(s[i])){
				cout<<s<<endl;
				flag=true;
				count++;
			}
			a[i]=s[i]-'0';
		}
		if(flag){
			continue;
		}
		if(s[17]=='X'){
			a[17]=10;
		}else{
			a[17]=s[17]-'0';
		}
		for(int i=0;i<17;i++){
			sum=sum+a[i]*b[i];
		}
		sum=sum%11;
		if(m[sum]!=a[17]){
			for(int i=0;i<17;i++){
				cout<<s[i];
			}
			if(a[17]!=10){
				cout<<a[17]<<endl;
			}else{
				cout<<"X"<<endl;
			}
			count++;
		}
	}
	if(count==0) {
		cout<<"All passed";
	}
	return 0;
}

