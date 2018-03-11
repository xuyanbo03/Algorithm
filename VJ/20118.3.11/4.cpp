#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin>>n;
	while(n--) {
		string s1,s2,tmp1,tmp2,tmp;
		cin>>s1;
		cin>>s2;
		tmp1=s1;
		tmp2=s2;
		int len1=s1.length();
		int len2=s2.length();
		tmp1=tmp1.substr(len1/2,len1);
		tmp2=s1.substr(0,tmp1.length());
		tmp=tmp2+s2+tmp1;
		cout<<tmp<<endl;
	}
	return 0;
}

