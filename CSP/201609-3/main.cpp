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

#define oponent 1-player
const int red=0;
const int black=1;
struct status{
	int life,power;
	status(int l,int a):life(l),power(a){}
};
vector<status> v[2];

int main(){
	int n;
	cin>>n;
	int player=red;
	string action;
	int position,attack,health;
	int attacker,defender;
	v[red].push_back(status(30,0));
	v[black].push_back(status(30,0));
	
	while(n--){
		cin>>action;
		if(action=="summon"){
			cin>>position>>attack>>health;
			v[player].insert(v[player].begin()+position,status(health,attack));
		}else if(action=="attack"){
			cin>>attacker>>defender;
			v[player][attacker].life-=v[oponent][defender].power;
			v[oponent][defender].life-=v[player][attacker].power;
			if(v[player][attacker].life<=0){
				v[player].erase(v[player].begin()+attacker);
			}
			if(defender!=0&&v[oponent][defender].life<=0){
				v[oponent].erase(v[oponent].begin()+defender);
			}
		}else if(action=="end"){
			player=oponent;
		}
	}
	
	if(v[red][0].life<=0){
		cout<<-1<<endl;
	}else if(v[black][0].life<=0){
		cout<<1<<endl;
	}else{
		cout<<0<<endl;
	}
	cout<<v[red][0].life<<endl;
	cout<<v[red].size()-1;
	for(int i=1;i<(int)v[red].size();i++){
		cout<<" "<<v[red][i].life;
	}
	cout<<endl;
	cout<<v[black][0].life<<endl;
	cout<<v[black].size()-1;
	for(int i=1;i<(int)v[black].size();i++){
		cout<<" "<<v[black][i].life;
	}
	cout<<endl;
	return 0;
}

