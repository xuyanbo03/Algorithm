#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        if(a.find(b)!=-1){
            cout<<"good"<<endl;
        }else{
            int flag=0;
            for(int i=0;i<b.length();i++){
                string s="";
                for(int j=0;j<b.length();j++){
                    if(i!=j){
                        s+=b[j];
                    }
                }
                if(a.find(s)!=-1){
                    flag=1;
                }
            }
            if(flag){
                cout<<"almost good"<<endl;
            }else{
                cout<<"none"<<endl;
            }
        }
    }
    return 0;
}