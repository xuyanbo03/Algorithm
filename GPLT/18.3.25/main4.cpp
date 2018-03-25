#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=1e8;
vector<string> v;
int main(){
	string s;
	for(int i=0;i<maxn;i++){
		cin>>s;
		if(s=="."){
			break;
		}
		v.push_back(s);
	}
	if(v.size()<1){
		cout<<"Momo... No one is for you ..."<<endl;
	}else if(v.size()>1&&v.size()<13){
		cout<<v[1]<<" is the only one for you..."<<endl;
	}else {
		cout<<v[1]<<" and "<<v[13]<<" are inviting you to dinner..."<<endl;
	}
	return 0;
}
