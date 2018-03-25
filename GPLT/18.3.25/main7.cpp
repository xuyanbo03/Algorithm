#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<math.h>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int n;
	float h,w,res;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>h>>w;
		float ans1=0.1*2*((h-100)*0.9);
		float ans=2*((h-100)*0.9);
		if(w-ans<0){
			res=-(w-ans);
		}else {
			res=w-ans;
		}
		if(res<ans1){
			cout<<"You are wan mei!"<<endl;
		}else if(w>ans){
			cout<<"You are tai pang le!"<<endl;
		}else if(w<ans){
			cout<<"You are tai shou le!"<<endl;
		}
	}
	return 0;
}
