#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    double str[10][3]={{0}};
    int n,i;
    cin>>n;
    for(i=0;i<n;i++){
        scanf("%lf %lf %lf",&str[i][0],&str[i][1],&str[i][2]);
    }
    for(int j=0;j<i;j++){
        if(str[j][0]+str[j][1]>str[j][2]){
            cout<<"Case #"<<j+1<<": true"<<endl;
        }else{
            cout<<"Case #"<<j+1<<": false"<<endl;
        }
    }
    return 0;
}