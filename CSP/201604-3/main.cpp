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

int main(){
	int p,pos;
	string cp,line;
	cin>>p>>cp;
	getchar();
	for(int i=0;i<p;i++){
		getline(cin,line);
		if(line[0]!='/'){
			line=cp+"/"+line+"/";
		}
		while((pos=line.find("//"))!=string::npos){
			int count=2;
			while(line[pos+count]=='/'){
				count++;
			}
			line.erase(pos,count-1);
		}
		while((pos=line.find("/./"))!=string::npos){
			line.erase(pos+1,2);
		}
		if(line.size()>1&&line[line.size()-1]=='/'){
			line.erase(line.size()-1);
		}
		while((pos=line.find("/../"))!=string::npos){
			if(pos==0){
				line.erase(pos,3);
			}else{
				int spos;
				spos=line.rfind("/",pos-1);
				line.erase(spos,pos-spos+3);
			}
			if(line.size()==0){
				line="/";
			}
		}
		cout<<line<<endl;
	}
	return 0;
}

