#include <iostream>
#include <string>
using namespace std;

int main(){
    string a,b;
    int da,db;
    cin>>a>>da>>b>>db;
    int count1=0,count2=0;
    int lena=a.length();
    int lenb=b.length();
    for(int i=0;i<lena;i++){
        if(da==(a[i]-'0')){
            count1++;
        }
    }
    for(int i=0;i<lenb;i++){
        if(db==(b[i]-'0')){
            count2++;
        }
    }
    int m=0,n=0;
    if(count1!=0){
        m=da;
    }
    if(count2!=0){
        n=db;
    }
    for(int i=1;i<count1;i++){
        m=m*10+da;
    }
    for(int i=1;i<count2;i++){
        n=n*10+db;
    }
    cout<<m+n;
    return 0;
}