#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

struct stu{
    int num;
    int d;
    int c;
};

//qsort
// int cmp(const void *i,const void *j){
//     struct stu *x = (struct stu *)i;
//     struct stu *y = (struct stu *)j;
//     if((x->d+x->c)!=(y->c)){
//         return (x->d+x->c)>(y->d+y->c);
//     }else if(x->d!=y->d){
//         return x->d>y->d;
//     }else{
//         return x->num<y->num;
//     }
// }

//sort()
int cmp (struct stu i,struct stu j) { 
    if((i.d+i.c)!=(j.d+j.c)){
        return (i.d+i.c)>(j.d+j.c);
    }else if(i.d!=j.d){
        return i.d>j.d;
    }else{
        return i.num<j.num;
    }
}

int main(){
    int n,l,h;
    cin>>n>>l>>h;
    int count=n;
    vector<stu> v[4];
    stu temp;
    for(int i=0;i<n;i++){
        cin>>temp.num>>temp.d>>temp.c;
        if(temp.d<l || temp.c<l){
            count--;
        }else if(temp.d>=h && temp.c>=h){
            v[0].push_back(temp);
        }else if(temp.d>=h && temp.c<h){
            v[1].push_back(temp);
        }else if(temp.d<h && temp.c<h && temp.d>=temp.c){
            v[2].push_back(temp);
        }else {
            v[3].push_back(temp);
        }
    }
    cout<<count<<endl;
    for(int i=0;i<4;i++){
        stable_sort(v[i].begin(),v[i].end(),cmp);
        //qsort(&v[i],v[i].size(),sizeof(v[i]),cmp);
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j].num<<" "<<v[i][j].d<<" "<<v[i][j].c<<endl;
        }
    }
    return 0;
}