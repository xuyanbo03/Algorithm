#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

int cmp(const void *a_t,const void *b_t){
    int *a = (int *)a_t;
    int *b = (int *)b_t;
    if(a[3]!=b[3]){
        return a[3]-b[3];
    }else if((a[1]+a[2])!=(b[1]+b[2])){
        return (b[1]+b[2])-(a[1]+a[2]);
    }else if(a[1]!=b[1]){
        return b[1]-a[1];
    }else{
        return a[0]-b[0];
    }
}

int main(){
    int n,l,h;
    cin>>n>>l>>h;
    int count=0;
    int num,de,cai,type;
    int stu[n][4];
    for(int i=0;i<n;i++){
        cin>>num>>de>>cai;
        if(de>=l&&cai>=l){
            count++;
            if(de>=h && cai>=h){
                type=1;
            }else if(de>=h && cai<h){
                type=2;
            }else if(de<h && cai<h && de>=cai){
                type=3;
            }else{
                type=4;
            }
        }
        stu[i][0]=num;
        stu[i][1]=de;
        stu[i][2]=cai;
        stu[i][3]=type;
    }
    qsort(&stu[0],n,sizeof(stu[0]),cmp);
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        cout<<stu[i][0]<<" "<<stu[i][1]<<" "<<stu[i][2]<<endl;
    }
    return 0;
}