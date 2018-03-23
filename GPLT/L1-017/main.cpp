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

int main(){
	string n;
	cin>>n;
	int len=n.length();
	bool flag=true;
	int count=0;
	if(n[0]=='-'){
		flag=false;
		len--;
	}
	for(int i=0;i<n.length();i++){
		if(!isdigit(n[i])){
			continue;
		}
		if((n[i]-'0')==2){
			count++;
		}
	}
	double res=(double)count/len;
	if(!flag){
		res=res*1.5;
	}
	if((n[n.length()-1]-'0')%2==0){
		res=res*2;
	}
	printf("%.2f",res*100);
	cout<<"%";
	return 0;
}

