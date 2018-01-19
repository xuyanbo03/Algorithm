#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int h,w,d;
        cin>>h>>w>>d;
        int t=2*w-2;
        int mod=h%t;
        if(mod>w){
            mod=2*w-mod;
        }else if(mod==0){
            mod=2;
        }
        if(mod==d){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}