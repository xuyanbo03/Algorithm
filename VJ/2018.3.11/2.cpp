#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
	int t;
	while(t--){
		int n,m,count=0;
		cin>>n>>m;
		
		while(n!=0){
			if(m-5>=0){
				m=m-5;
			}else if(m-2>=0){
				m=m-2;
			}else if(m-1>=0){
				m=m-1;
			}
		}
		count++;
		cout<<count<<endl;
	}
	return 0;
}

