#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    string a,b,c,d;
    for(int i=0;i<t;i++){
        cin>>a>>b;
        c="";
        d="";
        int lena=a.length();
        int lenb=b.length();
        for(int j=0;j<lena;j++){
            if(a[j]=='P'||a[j]=='p'){
                c+='b';
            }else if(a[j]=='I'||a[j]=='i'){
                c+='e';
            }else{
                c+=tolower(a[j]);
            }
        }
        for(int j=0;j<lenb;j++){
            if(b[j]=='B'||b[j]=='P'||b[j]=='b'||b[j]=='p'){
                d+='b';
            }else if(b[j]=='I'||b[j]=='E'||b[j]=='i'||b[j]=='e'){
                d+='e';
            }else{
                d+=tolower(b[j]);
            }
        }
        if(c==d){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        cout<<endl;
    }
    return 0;
}