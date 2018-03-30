#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	int maxv=0,tmp=0;
	int len=s.length();
	for(int i=0;i<len;i++){
		tmp=1;
		for(int j=1;j<len;j++){
			if(i-j<0||i+j>=len||s[i-j]!=s[i+j]){
				break;
			}
			tmp+=2;
		}
		maxv=tmp>maxv?tmp:maxv;
		tmp=0;
		for(int j=1;j<len;j++){
			if(i-j+1<0||i+j>=len||s[i-j+1]!=s[i+j]){
				break;
			}
			tmp+=2;
		}
		maxv=tmp>maxv?tmp:maxv;
	}
	cout<<maxv;
	return 0;
}
