#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

bool cmp(int a,int b){
    return (a>b);
}

int main(){
    string n;
    cin>>n;
    n.insert(0,4-n.length(),'0');
    do{
        string a=n,b=n;
        int ia=0,ib=0;
        sort(a.begin(),a.end(),cmp);
        sort(b.begin(),b.end());
        // C++11
        // int result=stoi(a)-stoi(b);
        // n=to_string(result);
        stringstream ss;
        ss<<a;
        ss>>ia;
        ss.clear();
        ss<<b;
        ss>>ib;
        ss.clear();
        int result=ia-ib;
        ss<<result;
        ss>>n;
        ss.clear();
        n.insert(0,4-n.length(),'0');
        cout<<a<<" - "<<b<<" = "<<n<<endl;
    }while(n!="0000"&&n!="6174");
    return 0;
}