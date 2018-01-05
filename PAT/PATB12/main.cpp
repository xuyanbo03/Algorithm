#include <iostream>
#include <cstdio>
using namespace std;
#define N 1000

int main(){
    int a1=0,a2=0,a3=0,a5=0;
    int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
    float a4=0.0;
    int a[N],b[N],c[N],d[N],e[N],f[N];
    int n;
    int count3=0,count4=0,t=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>f[i];
    }
    for(int i=0;i<n;i++){
        if(f[i]%10==0){
            a[i]=f[i];
            a1+=a[i];
            flag1=1;
        }
        if(f[i]%5==1){
            b[t++]=f[i];
            flag2=1;
        }
        if(f[i]%5==2){
            c[i]=f[i];
            count3++;
            flag3=1;
        }
        if(f[i]%5==3){
            d[i]=f[i];
            a4+=d[i];
            count4++;
            flag4=1;
        }
        if(f[i]%5==4){
            e[i]=f[i];
            if(e[i]>a5){
                a5=e[i];
            }
            flag5=1;
        }
    }
    for(int i=0;i<t;i++){
        if(i==0||i%2==0){
            a2+=b[i];
        }else{
            a2-=b[i];
        }
    }
    a4=a4/count4;
    
    if(flag1){
        cout<<a1<<" ";
    }else{
        cout<<"N"<<" ";
    }
    if(flag2){
        cout<<a2<<" ";
    }else{
        cout<<"N"<<" ";
    }
    if(flag3){
        a3 = count3;
        cout<<a3<<" ";
    }else{
        cout<<"N"<<" ";
    }
    if(flag4){
        printf("%.1f ",a4);
    }else{
        cout<<"N"<<" ";
    }
    if(flag5){
        cout<<a5;
    }else{
        cout<<"N";
    }
    return 0;
}