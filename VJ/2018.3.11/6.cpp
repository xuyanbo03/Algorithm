#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int n;
	int a[3]={0,0,0};
	cin>>n;
	for(int i=0;i<n;i++){
		int s;
		cin>>s;
		if(s==1){
			a[0]++;
		}else if(s==2){
			a[1]++;
		}else if(s==3){
			a[2]++;
		}
	}
	cout<<n-max(a[0],max(a[1],a[2]));
	return 0;
}

