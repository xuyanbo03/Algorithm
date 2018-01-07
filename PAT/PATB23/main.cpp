#include <iostream>
using namespace std;

int main(){
    int s[10];
    int num=0;
    for(int i=0;i<10;i++){
        cin>>s[i];
        num+=s[i];
    }
    int z[num];
    for(int i=1;i<10;i++){
        if(s[i]!=0){
            z[0]=i;
            s[i]--;
            break;
        }
    }
    int k=0;
    for(int i=0;i<10;i++){
        while(s[i]!=0){
            z[++k]=i;
            s[i]--;
        }
    }
    for(int i=0;i<num;i++){
        cout<<z[i];
    }
    return 0;
}