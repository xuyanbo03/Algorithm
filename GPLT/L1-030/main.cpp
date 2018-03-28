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
const int maxn=50;

struct student{
	int id,sex;
	string name;
	bool used=false;
}s[maxn];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		s[i].id=i;
		cin>>s[i].sex>>s[i].name;
	}
	for(int i=0;i<n/2;i++){
		int ss=s[i].sex;
		for(int j=n-1;j>=0;j--){
			if(ss!=s[j].sex&&s[j].used==false){
				cout<<s[i].name<<" "<<s[j].name<<endl;
				s[j].used=true;
				break;
			}
		}
	}
	return 0;
}

