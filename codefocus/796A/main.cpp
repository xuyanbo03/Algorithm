#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define N 500

using namespace std;

int main(){
	int n,m,k;
	int a[N];
	
	while(~scanf("%d %d %d",&n,&m,&k)){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		vector<int> s;
		for(int j=1;j<=n;j++){
			if(a[j]<=k&&a[j]!=0){
				//s[j]=abs(j-m);
				s.push_back(abs(j-m));
			}
		}
		sort(s.begin(),s.end());
		cout<<s[0]*10<<endl;
	}
	return 0;
}

//int main() {
//	int n,m,k;
//	int a[N];
//	
//	while(~scanf("%d%d%d",&n,&m,&k)){
//		for(int i=1;i<=n;i++){
//			cin>>a[i];
//		}
//		int s1,s2;
//		for(int i=m-1;i>=1;i--){
//			if(a[i]<=k&&a[i]!=0){
//				s1=m-i;
//				break;	
//			}
//		}
//		for(int i=m+1;i<=n;i++){
//			if(a[i]<=k&&a[i]!=0){
//				s2=i-m;
//				break;	
//			}
//		}
//		cout<<(min(s1,s2)*10)<<endl;
//	}
//	return 0;
//}
