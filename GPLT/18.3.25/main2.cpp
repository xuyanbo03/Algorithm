#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<math.h>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;

int main(){
	int h,m,count=0;
	scanf("%d:%d",&h,&m);
	if(h-12>0&&m==0){
		count=h-12;
	}else if(h-12>0&&m>0){
		count=h-12+1;
	}else {
		printf("Only %02d:%02d.  Too early to Dang.",h,m);
	}
	for(int i=0;i<count;i++){
		cout<<"Dang";
	}
	return 0;
}
