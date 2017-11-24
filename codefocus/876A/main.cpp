#include <iostream>
#include <cstdio>

using namespace std; 

int main() {
	int n,a,b,c;
	while(~scanf("%d",&n)){
		cin>>a>>b>>c;
		if(n==1){
			cout<<0<<endl;
		}else if(n==2){
			cout<<min(a,b)<<endl;
		}else{
			if(c<min(a,b)){
				cout<<(min(a,b)+(n-2)*c)<<endl;
			}else{
				cout<<((n-1)*min(a,b))<<endl;
			}
		}
	}
	return 0;
}
