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

int main(){
	int h,m;
	scanf("%d:%d",&h,&m);
	if(h-12<0||(m==0&&h-12==0)){
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
	}else{
		int count=h-12;
		if(m>0){
			count++;
		}
		while(count--){
			cout<<"Dang";
		}
	}
	return 0;
}

