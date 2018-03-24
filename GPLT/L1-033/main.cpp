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

int main(){
	int y,n;
	cin>>y>>n;
	for(int i=y;i<3500;i++){
		set<int> s;
		int num=i;
		for(int j=0;j<4;j++){
			s.insert(num%10);
			num/=10;
		}
		if(s.size()==n){
			printf("%d %04d",i-y,i);
			break;
		}
	}
	return 0;
}

