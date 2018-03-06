#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
int firstyear,lastyear;
int range[5]= {60,24,31,12,7};
int days[13]= {0,31,28,31,30,31,30,31,31,30,31,30,31};
string week[]= {"sun","mon","tue","wed","thu","fri","sat"};
string mon[]= {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"};
map<string,int> mp;
vector<pair<LL,int> > ans;

// 如果是字母开头，一定是英文缩写，直接返回mp中对应的值；否则就是数字，按位累加即可
int strToI(string &str) {
	if(isalpha(str[0])) {
		return mp[str];
	}
	int num=0;
	for(int i=0; i<str.size(); i++) {
		num=num*10+str[i]-'0';
	}
	return num;
}

void dealMinus(set<LL> &tmp,string &str) {
	for(int i=0; i<str.size(); i++) {
		str[i]=tolower(str[i]);
	}
	size_t tp=str.find('-');
	if(tp==string::npos) {
		tmp.insert(strToI(str));
	} else {
		string left=str.substr(0,tp),right=str.substr(tp+1);
		int l=strToI(left),r=strToI(right);
		for(int i=l; i<=r; i++) {
			tmp.insert(i);
		}
	}
}

// 先分析s是否为"*"，再分析','，最后分析'-'
void findValue(set<LL> &tmp,string &s,int j) {
	if(s=="*") {
		for(int i=0; i<range[j]; i++) {
			if(j==2||j==3) {
				tmp.insert(i+1);
			} else {
				tmp.insert(i);
			}
		}
		return;
	}
	s+=',';
	size_t pos=0,next=s.find(',');
	string str;
	while(next!=string::npos) {
		str=s.substr(pos,next-pos);
		dealMinus(tmp,str);
		pos=next+1;
		next=s.find(',',pos);
	}
}

// 分析y年m月d日是星期几，顺便排除一下不合法的日期比如11月31日
int getDay(int year,int month,int day) {
	days[2]=28;
	if((year%4==0&&year%100!=0)||(year%400==0)) {
		days[2]=29;
	}
	if(day>days[month]) {
		return -1;
	}
	int sum=4,q=year-1970;
	sum+=q/4*5+q%4;
	if(q%4==3) {
		++sum;
	}
	for(int i=1; i<month; i++) {
		sum+=days[i];
	}
	sum+=day-1;
	return sum%7;
}

// v[0] ~ v[3]不进行判断，只把tmp与pre中的内容组合起来，所有的判断放在v[4]中
void fillVector(vector<vector<LL> > &v,vector<LL> &tmp,int j,LL mul) {
	if(j==0) {
		v[j]=tmp;
	} else {
		vector<LL> &pre=v[j-1];
		if(j!=4) {
			for(int k=0; k<tmp.size(); k++) {
				for(int l=0; l<pre.size(); l++) {
					v[j].push_back(tmp[k]*mul+pre[l]);
				}
			}
		} else {
			int judge[7]= {0};
			for(int k=0; k<tmp.size(); k++) {
				judge[tmp[k]]=1;
			}
			for(int l=0; l<pre.size(); l++) {
				int month=pre[l]/1000000,day=pre[l]/10000%100;
				for(int year=firstyear; year<=lastyear; year++) {
					int dow=getDay(year,month,day);
					if(dow!=-1&&judge[dow]) {
						v[4].push_back(year*mul+pre[l]);
					}
				}
			}
		}
	}
}

int main() {
	for(int i=0; i<12; i++) {
		mp[mon[i]]=i+1;
	}
	for(int i=0; i<7; i++) {
		mp[week[i]]=i;
	}

	int n;
	LL begin,end;
	cin>>n>>begin>>end;
	firstyear=begin/100000000,lastyear=end/100000000;
	vector<vector<string> > cron(n,vector<string>(6));
	for(int i=0; i<n; i++) {
		for(int j=0; j<6; j++) {
			cin>>cron[i][j];
		}
	}

	for(int i; i<n; i++) {
		vector<vector<LL> > v(5);
		LL mul=1;
		for(int j=0; j<5; j++) {
			set<LL> valid;
			findValue(valid,cron[i][j],j);
			vector<LL> tmp;
			for(set<LL>::iterator it=valid.begin(); it!=valid.end(); it++) {
				tmp.push_back(*it);
			}
			fillVector(v,tmp,j,mul);
			mul*=100;
		}
		for(int j=0; j<v[4].size(); j++) {
			ans.push_back(make_pair(v[4][j],i));
		}
	}
	sort(ans.begin(),ans.end());
	for(vector<pair<LL,int> >::iterator it=ans.begin(); it!=ans.end(); it++) {
		if(it->first>=begin&&it->first<end) {
			cout<<it->first<<" "<<cron[it->second][5]<<endl;
		}
	}
	return 0;
}

