#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct stu{
    int num;
    int d;
    int c;
};

bool cmp (struct stu i,struct stu j) { 
    if((i.d+i.c)!=(j.d+j.c)){
        return (i.d+i.c)>(j.d+j.c);
    }else if(i.d!=j.d){
        return i.d>j.d;
    }else{
        return i.num>j.num;
    }
}

int main(){
    int n,l,h;
    int count=0;
    cin>>n>>l>>h;
    vector<stu> v[4];
    stu temp;
    for(int i=0;i<n;i++){
        cin>>temp.num>>temp.d>>temp.c;
        if(stu[i][1]>=l && stu[i][2]>=l){
            count++;
        }
    }
    cout<<count<<endl;
    for(int i=0;i<count;i++){
        int zong=pass[i][1]+pass[i][2];
        if(pass[i][1]>=h &&pass[i][2]>=h){
            std::sort(zong);
        }
        cout<<pass[i][1]<<endl;
    }
    
    return 0;
}