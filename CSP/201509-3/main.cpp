#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
const double epx=1e-10;
typedef long long ll;
const ll INF=1e18;

int main(){
	int n,m;
	vector<string> tv;
	string key,value,temp;
	map<string,string> dict;
	int prev,next;
	
	cin>>n>>m;
	getchar();
	for(int i=1;i<=n;i++){
		getline(cin,temp);
		tv.push_back(temp);
	}
	for(int i=1;i<=m;i++){
		cin>>key;
		getline(cin,value);
		dict[key]=value.substr(2,value.length()-3);
	}
	
	for(int i=0;i<n;i++){
		prev=0;
		for(;;){
			if((prev=tv[i].find("{{ ",prev))==(int)string::npos){
				break;
			}
			if((next=tv[i].find(" }}",prev))==(int)string::npos){
				break;
			}
			key=tv[i].substr(prev+3,next-prev-3);
			tv[i].replace(prev,key.length()+6,dict.count(key)?dict[key]:"");
			prev+=dict.count(key)?dict[key].length():0;
		}
		cout<<tv[i]<<endl;
	}
	return 0;
}

