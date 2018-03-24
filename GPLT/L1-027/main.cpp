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
	string s;
	cin>>s;
	int a[10]={0};
	for(int i=0;i<11;i++){
		a[s[i]-'0']++;
	}
	vector<int> arr;
	for(int i=9;i>=0;i--){
		if(a[i]!=0){
			arr.push_back(i);
		}
	}
	vector<int> index;
	for(int i=0;i<11;i++){
		for(int j=0;j<arr.size();j++){
			if((s[i]-'0')==arr[j]){
				index.push_back(j);
			}
		}
	}
	cout<<"int[] arr = new int[]{"<<arr[0];
	for(int i=1;i<arr.size();i++){
		cout<<","<<arr[i];
	}
	cout<<"};"<<endl;
	cout<<"int[] index = new int[]{"<<index[0];
	for(int i=1;i<index.size();i++){
		cout<<","<<index[i];
	}
	cout<<"};"<<endl;
	return 0;
}

