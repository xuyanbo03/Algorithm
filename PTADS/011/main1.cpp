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

int MaxSubseqSum1(int A[],int N){
	int ThisSum,MaxSum=0;
	int i,j,k;
	for(i=0;i<n;i++){
		for(j=i;j<N;j++){
			for(k=i;k<=j;k++){
				ThisSum+=A[k];
			}
			if(ThisSum>MaxSum){
				MaxSum=ThisSum;
			}
		}
	}
	return MaxSum;
}

int main(){
	return 0;
}

