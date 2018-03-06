#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
const int maxn=1000;
int a[maxn];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int max=0;
	for(int i=1;i<n;i++){
		int c=abs(a[i]-a[i-1]); 
		if(max<c){
			max=c;
		}
	}
	printf("%d",max);
	return 0;
}

