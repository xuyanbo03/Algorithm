#include <iostream>
#include <algorithm>
using namespace std;
#define N 100005

int main(){
    int first,n,k,tmp;
    cin>>first>>n>>k;
    int list[N],data[N],next[N];
    for(int i=0;i<n;i++){
        cin>>tmp;
        cin>>data[tmp];
        cin>>next[tmp];
    }
    int count=0;
    while(first!=-1){
        list[count++]=first;
        first=next[first];
    }
    for(int i=0;i<(count-count%k);i+=k){
        reverse(begin(list)+i,begin(list)+i+k);
    }
    for(int i=0;i<count-1;i++){
        printf("%05d %d %05d\n",list[i],data[list[i]],list[i+1]);
    }
    printf("%05d %d -1",list[count-1],data[list[count-1]]);
    return 0;
}