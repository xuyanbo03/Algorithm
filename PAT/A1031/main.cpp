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
	char str[100],ans[40][40];
	gets(str);
	int n=strlen(str);
	int n1=(n+2)/3;
	int n3=n1;
	int n2=n+2-n1-n3;
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			ans[i][j]=' ';
		}
	}
	int pos=0;
	for(int i=1;i<=n1;i++){
		ans[i][1]=str[pos++];
	}
	for(int i=2;i<=n2;i++){
		ans[n1][i]=str[pos++];
	}
	for(int i=n3-1;i>=1;i--){
		ans[i][n2]=str[pos++];
	}
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	return 0;
}

