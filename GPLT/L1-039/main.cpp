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
	int n;
	string s;
	cin>>n;
	getchar();
	getline(cin,s);
	int col=(s.length()-1)/n+1;
	vector<vector<char> > v(n,vector<char>(col,' '));
	int index=0;
	for(int j=col-1;j>=0;j--){
		for(int i=0;i<n;i++){
			if(index<s.length()){
				v[i][j]=s[index++];
			}
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<col;j++){
			cout<<v[i][j];
		}
		cout<<endl;
	}
	return 0;
}

