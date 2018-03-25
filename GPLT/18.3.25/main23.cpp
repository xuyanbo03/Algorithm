#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;

struct DATA{
	int id,fid,mid,num,area;
	int cid[10];
}data[1005];
struct node{
	int id,people;
	double num,area;
	bool flag=false;
}ans[10000];
bool cmp(node a,node b){
	if(a.area!=b.area){
		return a.area>b.area;
	}else{
		return a.id<b.id;
	}
}
int father[10000];
bool vis[10000];
int find(int x){
	while(x!=father[x]){
		x=father[x];
	}
	return x;
}
void uunion(int a,int b){
	int faa=find(a);
	int fab=find(b);
	if(faa>fab){
		father[faa]=fab;
	}else if(faa<fab){
		father[fab]=faa;
	}
}
int main(){
	int n,k,cnt=0;
	cin>>n;
	for(int i=0;i<10000;i++){
		father[i]=i;
	}
	for(int i=0;i<n;i++){
		cin>>data[i].id>>data[i].fid>>data[i].mid>>k;
		vis[data[i].id]=true;
		if(data[i].fid!=-1){
			vis[data[i].fid]=true;
			uunion(data[i].fid,data[i].id);
		}
		if(data[i].mid!=-1){
			vis[data[i].mid]=true;
			uunion(data[i].mid,data[i].id);
		}
		for(int j=0;j<k;j++){
			cin>>data[i].cid[j];
			vis[data[i].cid[j]]=true;
			uunion(data[i].cid[j],data[i].id);
		}
		cin>>data[i].num>>data[i].area;
	}
	for(int i=0;i<n;i++){
		int id=find(data[i].id);
		ans[id].id=id;
		ans[id].num+=data[i].num;
		ans[id].area+=data[i].area;
		ans[id].flag=true;
	}
	for(int i=0;i<10000;i++){
		if(vis[i]){
			ans[find(i)].people++;
		}
		if(ans[i].flag){
			cnt++;
		}
	}
	for(int i=0;i<10000;i++){
		if(ans[i].flag){
			ans[i].num=(double)(ans[i].num*1.0/ans[i].people);
			ans[i].area=(double)(ans[i].area*1.0/ans[i].people);
		}
	}
	sort(ans,ans+10000,cmp);
	cout<<cnt<<endl;
	for(int i=0;i<cnt;i++){
		printf("%04d %d %.3f %.3f\n",ans[i].id,ans[i].people,ans[i].num,ans[i].area);
	}
	return 0;
}

