#include<bits/stdc++.h>
using namespace std;

int main() {
	map<int,string> a;
	a.insert(make_pair(0,"ling"));
	a.insert(make_pair(1,"yi"));
	a.insert(make_pair(2,"er"));
	a.insert(make_pair(3,"san"));
	a.insert(make_pair(4,"si"));
	a.insert(make_pair(5,"wu"));
	a.insert(make_pair(6,"liu"));
	a.insert(make_pair(7,"qi"));
	a.insert(make_pair(8,"ba"));
	a.insert(make_pair(9,"jiu"));
	a.insert(make_pair(-1,"fu"));
	string s;
	cin>>s;
	int len=s.length();
	if(s[0]=='-') {
		cout<<a[-1];
		for(int i=1; i<len; i++) {
			cout<<" "<<a[s[i]-'0'];
		}
	} else {
		for(int i=0; i<len; i++) {
			if(i==0){
				cout<<a[s[i]-'0'];
				continue;
			}
			cout<<" "<<a[s[i]-'0'];
		}
	}
	return 0;
}

