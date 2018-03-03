#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm> 
using namespace std;

int randPartition(int a[],int left,int right){
	int p=(int)(1.0*rand()/RAND_MAX*(right-left)+left);
	swap(a[p],a[left]);
	int temp=a[left];
	while(left<right){
		while(left<right&&a[right]>temp){
			right--;
		}
		a[left]=a[right];
		while(left<right&&a[left]<temp){
			left++;
		}
		a[right]=a[left];
	}
	a[left]=temp;
	return left;
}
void quickSort(int a[],int left,int right){
	if(left<right){
		int pos=randPartition(a,left,right);
		quickSort(a,left,pos-1);
		quickSort(a,pos+1,right);
	}
}

int main(){
	srand((unsigned)time(NULL));
	int n=10;
	int a[n]={1,5,9,8,6,25,3,56,45,4};
	quickSort(a,0,n-1);
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	return 0;
}

