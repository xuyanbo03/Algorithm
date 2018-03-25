#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<algorithm>
using namespace std;
const int maxn=1e8;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int day,h,m;
		scanf("%d %d:%d",&day,&h,&m);
		if(day==0){
			printf("%d %02d:%02d\n",day,h,m);
			continue;
		}
		int wd,wh,wm;
		wd=day/2;
		wh=h/2+12;
		wm=m/2+30;
		if(wm>59){
			wm-=59;
			wh+=1;
		}
		if(wh>23){
			wd+=1;
			wh-=23;
		}
		if(day==1){
			printf("%d %02d:%02d\n",day,h/2,m/2);
			continue;
		}
		if(day==2){
			printf("%d %02d:%02d\n",day/2,wh,wm);
			continue;
		}
		if(day==3){
			printf("%d %02d:%02d\n",day/2+1,h/2,m/2);
			continue;
		}
		if(day==4){
			printf("%d %02d:%02d\n",day/2,wh,wm);
			continue;
		}
		if(day==5){
			printf("%d %02d:%02d\n",day/2+1,h/2,m/2);
			continue;
		}
		if(day==6){
			printf("%d %02d:%02d\n",day/2,wh,wm);
			continue;
		}
	}

	return 0;
}
