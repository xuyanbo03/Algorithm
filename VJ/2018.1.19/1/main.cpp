#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n,r;
        cin>>n>>r;
        int a[n+5];
        int sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum+1500==r){
            cout<<"Correct";
        }else{
            cout<<"Bug";
        }
        cout<<endl;
    }
    return 0;
}