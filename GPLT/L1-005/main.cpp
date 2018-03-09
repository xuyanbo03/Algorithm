#include<bits/stdc++.h>
using namespace std;

struct stu{
	string z;
	int s;
	int k;
};

int main(){
	int n,m;
	cin>>n;
	stu a[1010];
	for(int i=0;i<n;i++){
		cin>>a[i].z>>a[i].s>>a[i].k;
	}
	cin>>m;
	int s;
	while(m--){
		cin>>s;
		for(int i=0;i<n;i++){
			if(a[i].s==s){
				cout<<a[i].z<<" "<<a[i].k<<endl;
			}
		}
	}
	return 0;
}

