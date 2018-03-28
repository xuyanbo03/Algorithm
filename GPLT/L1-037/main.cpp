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
	int a,b;
	scanf("%d %d",&a,&b);
	if(b==0){
		printf("%d/%d=Error",a,b);
	}else if(b<0){
		printf("%d/(%d)=%.2f",a,b,(double)a/b);
	}else{
		printf("%d/%d=%.2f",a,b,(double)a/b);
	}
	return 0;
}

