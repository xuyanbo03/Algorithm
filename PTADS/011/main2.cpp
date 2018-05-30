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

int MaxSubseqSum2(int A[],int N){
	int ThisSum,MaxSum=0;
	int i,j;
	for(i=0;i<N;i++){
		ThisSum=0;
		for(j=i;j<n;j++){
			ThisSum+=A[j];
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

