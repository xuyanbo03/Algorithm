#include <iostream>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[100005];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int l=0;
        int r=a[n-1]/k+1;
        while(l<=r){
            int mid=(r+l)/2;
            int x=a[0]+mid-1;
            int num=1;
            for(int i=0;i<n;i++){
                if(a[i]>x){
                    num++;
                    x=a[i]+mid-1;
                }
            }
            if(num<=k){
                r=mid-1;
            }else{
                l=mid+1;
            }
        }
        cout<<r+1<<endl;
    }
}