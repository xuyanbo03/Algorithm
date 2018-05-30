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

int MaxSubseqSum4(int A[],int N){
	int ThisSum,MaxSum;
	int i;
	ThisSum=MaxSum=0;
	for(i=0;i<N;i++){
		ThisSum+=A[i];
		if(ThisSum>MaxSum){
			MaxSum=ThisSum;
		}else if(ThisSum<0){
			ThisSum=0;
		}
	}
	return MaxSum;
}

int main(){
	return 0;
}
