#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 50000
using namespace std;

//struct myclass{
//	bool operator()(int i,int j){
//		return (i<j);
//	}
//}myobject;

int main(){
	int n;
	while(~scanf("%d",&n)){
		int a[N];
		//vector<int> myvector(a,a+N);
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			cout<<a[i]<<endl;
		}
//		sort(myvector.begin(),myvector.end()+n,myobject);
//		for(vector<int>::iterator it=myvector.begin();it!=myvector.end();it++){
//			cout<<*it<<endl;
//		}
	}
	return 0;
}
