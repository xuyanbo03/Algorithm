#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string s;
	cin>>s;
	int count=0; 
	int len=s.length();
	for(int i=0;i<len;i++){
		for(int j=i+1;j<len;j++){
			if(s[i]==s[j]){
				count++;
			}
		}
	}
	cout<<(count*2+len);
	return 0;
}

