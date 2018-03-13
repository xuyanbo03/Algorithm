#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int cmp(const void *a_t,const void *b_t){
    double *a=(double *)a_t;
    double *b=(double *)b_t;
    return a[2]<b[2];
}

int main(){
    int n,d;
    cin>>n>>d;
    double good[n][3];
    for(int i=0;i<2;i++){
        for(int j=0;j<n;j++){
            cin>>good[j][i];
        }
    }
    for(int i=0;i<n;i++){
        good[i][2]=good[i][1]/good[i][0];
    }
    qsort(&good[0],n,sizeof(good[0]),cmp);
    double tmp=d;
    double p=0;
    for(int i=0;i<n;i++){
        if(good[i][0]<=tmp){
            p+=good[i][1];
            tmp-=good[i][0];
        }else{
            p+=(good[i][2]*tmp);
            break;
        }
    }
    printf("%.2f",p);
    return 0;
}