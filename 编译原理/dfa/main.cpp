#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class TransTile
{
public:
	char current;
	char next;
	char input;
	TransTile(char C,char I,char Ne){
		current = C;
		next = Ne;
		input = I;
	}
};

class DFA
{
public:
	string States;
	char startStates;
	string finalStates;
	string Alphabets;
	vector <TransTile> Tile;

	DFA(){
		init();
	}

	void init()
	{
		cout << "输入有限状态集S：" << endl;
		cin >> States;
		cout << "输入字符集A：" << endl;
		cin >> Alphabets;
		cout << "输入状态转换式，输入#结束：" << endl;
		while(true){
			char input[4];
			cin>>input;
			if(strcmp(input,"#")==0)
				break;
			TransTile transval(input[0],input[1],input[2]);
			Tile.push_back(transval);
		}
		cout << "输入初态：" << endl;
		cin >> startStates;
		cout << "输入终态：" << endl;
		cin >> finalStates;
	}

	//遍历转换表
	char move(char P,char I){
		for (int i = 0; i < Tile.size(); i++){
			if (Tile[i].current == P&&Tile[i].input == I){
				return Tile[i].next;
			}
		}
		return 'E';
	}

	//识别字符串函数
	void recognition(){
		string str;
		cout << "输入需要识别的字符串：" << endl;
		cin >> str;
		int i = 0;
		char current = startStates;
		while (i < str.length()){
			current = move(current, str[i]);
			if (current == 'E'){
				break;
			}
			i++;
		}
		if (finalStates.find(current) != finalStates.npos){
			cout << "该自动机识别该字符串！" << endl;
		}
		else
		{
			cout << "该自动机不能识别该字符串！" << endl;
		}
	}
};

int main(){
	DFA dfa;
	bool flag=1;

	while(flag){
		if(flag){
			dfa.recognition();
            cout << "输入1继续，0退出！" << endl;
            cin>>flag;
		}else{
            break;
        }
	}

	return 0;
}

//输入有限状态集S：
//S,U,V,Q
//输入字符集A：
//a,b
//输入状态转换式，输入#结束：
//SaU
//UaQ
//VaU
//QaQ
//SbV
//UbV
//VbQ
//QbQ
//#
//输入初态：
//S
//输入终态：
//Q