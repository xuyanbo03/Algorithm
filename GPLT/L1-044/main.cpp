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

int main() {
	string str1="ChuiZi";
	string str2="JianDao";
	string str3="Bu";
	int k,count=0;
	cin>>k;
	getchar();
	string s;
	while(cin>>s) {
		if(s=="End"){
			break;
		}
		if(count<k) {
			if(s==str1) {
				cout<<str3<<endl;
				count++;
			}
			if(s==str2){
				cout<<str1<<endl;
				count++;
			}
			if(s==str3){
				cout<<str2<<endl;
				count++;
			}
		}else{
			cout<<s<<endl;
			count=0;
		}
	}
	return 0;
}

