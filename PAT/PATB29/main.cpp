#include <iostream>
#include <cctype>
using namespace std;

int main(){
    string a,b;
    cin>>a>>b;
    int lena=a.length();
    int lenb=b.length();
    int count=0;
    char c[80];
    for(int i=0;i<lena;i++){
        int flag=0;
        for(int j=0;j<lenb;j++){
            if(a[i]==b[j]){
                flag=1;
                break;
            }
        }
        if(!flag){
            c[count++]=toupper(a[i]);
        }
    }
    for(int i=1;i<count;i++){
        for(int j=0;j<i;j++){
            if(c[i]==c[j]){
                c[i]='#';
                break;
            }
        }
    }
    for(int i=0;i<count;i++){
        if(c[i]!='#'){
            cout<<c[i];
        }
    }
    return 0;
}