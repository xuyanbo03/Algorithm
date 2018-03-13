#include <iostream>
#include <algorithm>
using namespace std;

struct good{
    double m;
    double p;
    double u;
};

int cmp(good a,good b){
    return a.u>b.u;
}

int main(){
    int n,d;
    cin>>n>>d;
    good *a=new good[n];
    for(int i=0;i<n;i++){
        cin>>a[i].m;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].p;
    }
    for(int i=0;i<n;i++){
        a[i].u=a[i].p/a[i].m;
    }
    sort(a,a+n,cmp);
    double tmp=d;
    double pf=0;
    for(int i=0;i<n;i++){
        if(a[i].m<=tmp){
            pf+=a[i].p;
            tmp-=a[i].m;
        }else{
            pf+=(a[i].u*tmp);
            break;
        }
    }
    printf("%.2f",pf);
    delete []a;
    return 0;
}