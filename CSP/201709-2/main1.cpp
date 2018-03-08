#include<bits/stdc++.h>
using namespace std;

struct teacher{
	int num,s,e;
	teacher(int x=0,int y=0,int z=0):num(x),s(y),e(z){}
};

vector<teacher> p,q;
int n,k;
int key[1010]={0};

bool cmpp(const teacher &a,const teacher &b){
	return a.s<b.s;
}
bool cmpq(const teacher &a,const teacher &b){
	return a.e==b.e?a.num<b.num:a.e<b.e;
}
int searchKey(int keyid){
	for(int i=1;i<=n;i++){
		if(keyid==key[i]){
			return i;
		}
	}
	return -1;
}

int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		key[i]=i;
	}
	for(int i=0;i<k;i++){
		teacher x;
		scanf("%d%d%d",&x.num,&x.s,&x.e);
		x.e+=x.s;
		p.push_back(x);
		q.push_back(x);
	}
	sort(p.begin(),p.end(),cmpp);
	sort(q.begin(),q.end(),cmpq);
	
	int i=0,j=0;
	while(i<k&&j<k){
		if(p[i].s<q[j].e){
			int pos=searchKey(p[i++].num);
			key[pos]=-1;
		}else if(p[i].s>=q[j].e){
			int pos=searchKey(-1);
			key[pos]=q[j++].num;
		}
	}
	while(j<k){
		int pos=searchKey(-1);
		key[pos]=q[j++].num;
	}
	for(int i=1;i<=n;i++){
		printf("%d ",key[i]);
	}
	return 0;
}
