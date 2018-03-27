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
int c[4];
int main(){
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;i++){
		if(toupper(s[i])=='G'){
			c[0]++;
		}else if(toupper(s[i])=='P'){
			c[1]++;
		}else if(toupper(s[i])=='L'){
			c[2]++;
		}else if(toupper(s[i])=='T'){
			c[3]++;
		}
	}
	while(c[0]!=0||c[1]!=0||c[2]!=0||c[3]!=0){
		for(int i=0;i<4;i++){
			if(c[i]!=0){
				c[i]--;
				if(i==0){
					cout<<"G";
				}else if(i==1){
					cout<<"P";
				}else if(i==2){
					cout<<"L";
				}else {
					cout<<"T";
				}
			}
		}
	}
	return 0;
}

