#include <iostream>
#include <cstdio>
#define N 100000

using namespace std;

int main() {
	int a,b,c,d;
	int flag=0;
	//cin>>a>>b;
	//cin>>c>>d;
	while(~scanf("%d %d %d %d",&a,&b,&c,&d)){
		int ans=N;
		flag=0;
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(b+i*a==d+j*c){
					ans=min(ans,d+j*c);
					flag=1;
				}
			}
		}
		if(flag) {
			cout<<ans<<endl;
		}else{
			cout<<(-1)<<endl;
		}
	}
	return 0;
}
