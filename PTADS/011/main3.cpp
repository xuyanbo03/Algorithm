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

int MAx3(int A,int B,int C){
	return A>B ? A>C?A:C : B>C?B:C;
}

//分治
int DivideAndConquer(int List[],int left,int right){
	int MaxLeftSum,MaxRightSum;
	int MaxLeftBorderSum,MaxRightBorderSum;
	int LeftBorderSum, RightBorderSum;
    int center, i;
    
    //递归终止条件,子列只有一个数字 
    if(left==right){
    	if(List[left]>0){
    		return List[left];
		}else{
			return 0;
		}
	}
	
	//分 
	center=(left+right)/2;
	//递归求两边子列 
	MaxLeftSum=DivideAndConquer(List,left,center);
	MaxRightSum=DivideAndConquer(List,center,right);
	
	//求跨分界线最大子列和
	MaxLeftBorderSum=0;
	LeftBorderSum=0;
	for(i=center;i>=left;i--){
		LeftBorderSum+=List[i];
		if(LeftBorderSum>MaxLeftBorderSum){
			MaxLeftBorderSum=LeftBorderSum;
		}
	}
	MaxRightBorderSum=0;
	RightBorderSum=0;
	for(i=center;i<=right;i++){
		RightBorderSum+=List[i];
		if(RightBorderSum>MaxRightBorderSum){
			MaxRightBorderSum=RightBorderSum;
		}
	}
	
	//治
	return MAx3(MaxLeftSum,MaxRightSum,MaxLeftBorderSum+MaxRightBorderSum); 
}

int MaxSubseqSum3(int List[],int N){
	return DivideAndConquer(List,0,N-1);
}

int main(){
	return 0;
}

