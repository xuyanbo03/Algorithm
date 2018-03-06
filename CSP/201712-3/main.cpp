#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int firstyear,lastyear;
int range[5]={60,24,31,12,7};
int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
string week[]={"sun","mon","tue","wed","thu","fri","sat"};
string mon[]={"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
map<string,int> mp;
vector<pair<LL,int>> ans;

int strToI(string &str){
	if(isalpha(str[0])){
		return mp[str];
	}
	int num=0;
	for(int i=0;i<str.size();i++){
		
	}
}

int main(){
	cout<<1;
	return 0;
}

