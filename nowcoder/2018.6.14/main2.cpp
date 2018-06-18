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

struct tc{
	int x;
	int y;
	double dj;
}a[1005];

int cmpp(tc a1,tc a2){
	if(a1.dj<=a2.dj){
		return true;
	}else{
		return false;
	}
}

int main(){
	int n,m,k,t1,t2;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d %d",&t1,&t2);
		a[i].x=t1;
		a[i].y=t2; 
		a[i].dj=(double)t1/t2;
	}
	sort(a,a+m,cmpp);
	int people=n+1;
	int money=0;
	while(1){
		if(people>=a[0].y){
			money+=a[0].x;
			people-=a[0].y;
		}else{
			break;
		}
	}
	for(int i=1;i<m;i++){
		if(a[i].dj>=k){
			break;
		}
		if(people>=a[i].y){
			money+=a[i].x;
			people-=a[i].y;
		}
	}
	if(people!=0){
		money+=k;
		people--;
	}
	printf("%d\n",money);
	return 0;
}

//背包问题 

//题目描述
//今年的世界杯要开始啦，牛牛作为一个球迷，当然不会放过去开幕式现场的机会。但是牛牛一个人去又觉得太过寂寞，便想叫上了他的n个小伙伴陪他一起去莫斯科(一共n+1人)。当牛牛开始订开幕式的门票时，发现门票有m种套餐，每种套餐需要花费x元，包含y张门票，每张门票也可以单独购买，此时这张门票的价格为k元。请问牛牛要怎样选择购买门票，使得他花费的钱最少。(每种套餐可以购买次数没有限制)。
//输入描述:
//第一行输入三个数字n(0≤n≤999)、m(1≤m≤1000)和k(1≤k≤100000)
//接下来m行，每行输入两个数字xi(1≤xi≤100000)和yi(2≤yi≤1000), 表示套餐的价格和套餐内包含的门票数量。
//输出描述:
//输出牛牛至少要花费的钱的数量。
//示例1
//输入
//2 2 5
//6 2
//13 3
//输出
//11
