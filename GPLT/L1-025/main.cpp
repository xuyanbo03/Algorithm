#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<cctype>
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

bool islegal(string s){
	if(s.length()==0){
		return false;
	}
	for(int i=0;i<s.length();i++){
		if(!isdigit(s[i])){
			return false;
		}
	}
	int tmp=stoi(s);
	if(tmp<1||tmp>1000){
		return false;
	}
	return true;
}

int main(){
	string a,b,t;
	getline(cin,t);
	for(int i=0;i<t.length();i++){
		if(t[i]==' '){
			a=t.substr(0,i);
			b=t.substr(i+1,t.size()-i-1);
			break;
		}
	}
	if(!islegal(a)){
		a="?";
	}
	if(!islegal(b)){
		b="?";
	}
	cout<<a<<" + "<<b<<" = ";
	if(a!="?"&&b!="?"){
		int at=stoi(a);
		int bt=stoi(b);
		cout<<at+bt;
	}else{
		cout<<"?";
	}
	return 0;
}

