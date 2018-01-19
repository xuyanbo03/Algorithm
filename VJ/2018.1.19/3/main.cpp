#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n,sum=1;
        cin>>n;
        string a,b;
        cin>>a>>b;
        for(int j=0;j<n;j++){
            if(a[j]=='1'&&b[j]=='0'){
                sum=0;
            }else if(a[j]=='1'&&b[j]=='1'){
                sum*=2;
            }else{
                sum*=1;
            }
            sum=sum%1000000007;
        }
        sum=sum%1000000007;
        if(sum!=0){
            cout<<sum;
        }else{
            cout<<"IMPOSSIBLE";
        }
        cout<<endl;
    }
    return 0;
}