#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    long long p;
    cin>>n>>p;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int len=0;
    for(int i=0;i<n;i++){
        for(int j=i+len;j<n;j++){
            if(a[i]*p>=a[j]){
                len=j-i+1;
            }else{
                break;
            }
        }
    }
    cout<<len;
    return 0;
}