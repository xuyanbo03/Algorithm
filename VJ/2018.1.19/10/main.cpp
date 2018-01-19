#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[10005],b[10005],dp[10005];
        // memset(dp,0,sizeof(dp));
        for(int i=0;i<10005;i++){
            dp[i]=0;
        }
        for(int i=1;i<=n;i++){
            int num=0;
            int sum=1;
            cin>>a[i];
            while(a[i]%sum==0){
                num++;
                sum*=2;
            }
            b[i]=num-1;
            dp[i]=num-1;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>a[j]){
                    dp[i]=max(dp[i],b[i]+dp[j]);
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,dp[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}