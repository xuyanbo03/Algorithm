#include <iostream>
using namespace std;

int main(){
    int a,b,d;
    cin>>a>>b>>d;
    int c=a+b;
    int s[100];
    int i=0;
    if(c==0){
        cout<<0;
        return 0;
    }
    while(c!=0){
        s[i++]=c % d;
        c = c / d;
    }
    for(int j=i-1;j>=0;j--){
        cout<<s[j];
    }
    return 0;
}