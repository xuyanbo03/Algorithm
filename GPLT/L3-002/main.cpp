#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<algorithm>
#define lowbit(i) ((i)&(-i))
using namespace std;
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;
const int maxn=100010;
int c[maxn];
stack<int> s;

void update(int x,int v){
	for(int i=x;i<maxn;i+=lowbit(i)){
		c[i]+=v;
	}
}
int getsum(int x){
	int sum=0;
	for(int i=x;i>=1;i-=lowbit(i)){
		sum+=c[i];
	}
	return sum;
}
void peekMedian(){
	int left=1,right=maxn,mid,k=(s.size()+1)/2;
	while(left<right){
		mid=left+(right-left)/2;
		if(getsum(mid)>=k){
			right=mid;
		}else{
			left=mid+1;
		}
	}
	printf("%d\n",left);
}
int main(){
	int n,t;
	scanf("%d", &n);
	char str[15];
	for(int i=0;i<n;i++){
		scanf("%s", str);
		if(str[1]=='u'){
			scanf("%d", &t);
			s.push(t);
			update(t,1);
		}else if(str[1]=='o'){
			if(!s.empty()){
				update(s.top(),-1);
				printf("%d\n",s.top());
				s.pop();
			}else{
				printf("Invalid\n");
			}
		}else {
			if(!s.empty()){
				peekMedian();
			}else{
				printf("Invalid\n");
			}
		}
	}
	return 0;
}

