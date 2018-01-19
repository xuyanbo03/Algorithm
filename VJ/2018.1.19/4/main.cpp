#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int r,c,i;
        int r1,r2,c1,c2;
        char col;
        cin>>r>>c>>i;
        char a[r][c];
        for(int k=0;k<r;k++){
            for(int l=0;l<c;l++){
                a[k][l]='.';
            }
        }
        for(int j=0;j<i;j++){
            cin>>r1>>c1>>r2>>c2>>col;
            for(int m=r1-1;m<r2;m++){
                for(int n=c1-1;n<c2;n++){
                    a[m][n]=col;
                }
            }
        }
        for(int k=0;k<r;k++){
            for(int l=0;l<c;l++){
                cout<<a[k][l];
            }
            cout<<endl;
        }
    }
    return 0;
}