#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,d,r;
        cin>>n>>d>>r;
        int a[100005];
        int b[100005];
        // memset(a,0,sizeof(a));
        // memset(b,0,sizeof(b));
        for(int i=0;i<100005;i++){
            a[i]=0;
        }
        for(int i=0;i<100005;i++){
            b[i]=0;
        }
        int s1=d;
        int s2=r;
        int num=0;
        while(1){
            num++;
            s1=s1%n;
            s2=s2%n;
            a[s1]=1;
            b[s2]=1;
            if((a[s1]&&b[s1])||(a[s2]&&b[s2])){
                cout<<num<<endl;
                break;
            }
            s1+=d;
            s2+=r;
        }
    }
    return 0;
}