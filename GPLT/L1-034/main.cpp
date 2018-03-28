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
	int n,k,t,maxIndex=0,maxValue=0;
	int arr[1001]={0};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>t;
			arr[t]++;
		}
	}
	for(int i=0;i<1001;i++){
		if(arr[i]>=maxValue){
			maxIndex=i;
			maxValue=arr[i];
		}
	}
	cout<<maxIndex<<" "<<maxValue;
	return 0;
}

