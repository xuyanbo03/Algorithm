#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD=1e18;
const int N=1e5+10;
ll v[N],f[N],u[N],s[N];
ll ans[N];
int vis[N];//vis���鱣��������ֱ���¼����� 

void init(){
	memset(ans,0,sizeof(ans));
	memset(vis,0,sizeof(vis));
}
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d%d",&u[i],&s[i],&v[i],&f[i]);
			vis[u[i]]++;
		}
		//�������� 
		int q[N],q0=0,q1=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]){
				q[q1++]=i;
			}
		}
		
		while(q0<q1){
			int k=q[q0++];
			int t=u[k],d=s[k];
			vis[t]--;
			//ֱ���¼�ȫ��������ˣ����
			if(!vis[t]){
				q[q1++]=t;
			}
			//Ѱ�������ϼ��������ϼ����е�����Ļ�����ȡ���ֵ
			while(t){
				//ans�ﱣ�������������Ϊ��ͷ����·����ֵ 
				ans[t]=max(ans[t],(ans[k]+v[t]-(f[t]-d)*(f[t]-d)));
				d+=s[t];
				t=u[t];
			}
		}
		ll sum=0;
		for(int i=1;i<=n;i++){
			sum=(sum+ans[i])%MOD;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
