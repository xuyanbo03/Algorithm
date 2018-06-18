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
	int n;
	cin>>n;
	char a[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
		}
	}
	int dx[]={1,-1,0,0};
	int dy[]={0,0,1,-1};
	int ss=inf;
	int s=inf;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;i++){
			if(a[i][j]=='@'){
				s=dijstra();
				if(s<ss){
					ss=s;
				}
			}
		}
	}
	cout<<ss<<endl;
	return 0;
}

//最短路径 

//题目描述
//又是晴朗的一天，牛牛的小伙伴们都跑来找牛牛去公园玩。但是牛牛想呆在家里看E3展，不想出去逛公园，可是牛牛又不想鸽掉他的小伙伴们，于是找来了公园的地图，发现公园是由一个边长为n的正方形构成的，公园一共有m个入口，但出口只有一个。公园内有一些湖和建筑，牛牛和他的小伙伴们肯定不能从他们中间穿过，所以只能绕行。牛牛想知道他需要走的最短距离并输出这个最短距离。
//输入描述:
//第一行输入一个数字n(1≤n≤1000)表示公园的边长
//接下来会给你一个n*n的公园地图，其中 . 表示公园里的道路，@表示公园的入口，*表示公园的出口，#表示公园内的湖和建筑。牛牛和他的小伙伴们每次只能上下左右移动一格位置。
//输入保证公园入口个数m(1≤m≤10000)且所有的入口都能和出口相连。
//输出描述:
//输出牛牛需要行走的最短距离。
//示例1
//输入
//10
//.@....##@.
//......#...
//...@..#...
//###.......
//....##..#.
//...####...
//@...##....
//#####.....
//..##*####.
//#.........
//输出
//16
