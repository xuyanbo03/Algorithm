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
int book[256];
int main(){
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int lena=a.length();
	int lenb=b.length();
	for(int i=0;i<lenb;i++){
		book[b[i]]=1;
	}
	for(int i=0;i<lena;i++){
		if(book[a[i]]==1){
			continue;
		}
		cout<<a[i];
	}
	return 0;
}

