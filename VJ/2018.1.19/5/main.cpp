#include <iostream>
using namespace std;

int gcd(int a,int b){
    if(b!=0){
        return gcd(b,a%b);
    }else{
        return a;
    }
}

int main(){
    int t;
    int a[1000000];
    cin>>t;
    while(t--){
        int n,count,sum=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            if(i==0){
                count=a[i];
            }else{
                count=gcd(a[i],count);
            }
        }
        cout<<count<<" "<<sum/count<<endl;
    }
    return 0;
}