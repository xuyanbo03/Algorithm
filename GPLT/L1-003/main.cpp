#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[10]={0};
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		a[s[i]-'0']++;
	}
	for(int i=0;i<10;i++){
		if(a[i]>0){
			cout<<i<<":"<<a[i]<<endl;
		}
	}
	return 0;
}

