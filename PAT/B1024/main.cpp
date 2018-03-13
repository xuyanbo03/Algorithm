#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int s1=(s[0]=='+'?0:1);
    int eloc=s.find('E');
    int s2=(s[eloc+1]=='+'?0:1);
    string sp=s.substr(1,eloc-1);
    string sa=s.substr(eloc+2,s.size()-eloc-2);
    stringstream ss;
    int index=0;
    ss<<sa;
    ss>>index;
    ss.clear();

    if(s1==1){
        cout<<'-';
    }
    if(s2==1){
        for(int i=0;i<index;i++){
            cout<<0;
            if(i==0){
                cout<<'.';
            }
        }
        cout<<s[1];
        for(int j=3;j<eloc;j++){
            cout<<s[j];
        }
    }else if(s2==0){
        cout<<sp[0];
        int count=0;
        for(int i=2;i<sp.size();i++){
            if(index==count){
                cout<<".";
            }
            cout<<sp[i];
            ++count;
        }
        for(int j=0;j<index-count;j++){
            cout<<0;
        }
    }
    return 0;
}