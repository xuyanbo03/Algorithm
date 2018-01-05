#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int k){
    for(int i=2;i<=sqrt(k);i++){
        if(k%i==0){
            return false;
        }
    }
    return true;
}

bool dec(int a){
    if(a%10==0){
        return true;
    }else{
        return false;
    }
}

int main(){
    int m,n,j=0,k=0;
    cin>>m>>n;
    int p[n];
    for(int i=2;k<n;i++){
        if(isPrime(i)){
            k++;
            if(k>=m){
                p[++j]=i;
            }
        }
    }
    for(int i=1;i<j;i++){
        if(dec(i)){
            cout<<p[i]<<endl;
        }else{
            cout<<p[i]<<" ";
        }
    }
    cout<<p[j];
    return 0;
}

// 1013. 数素数 (20)
// 时间限制
// 100 ms
// 内存限制
// 65536 kB
// 代码长度限制
// 8000 B
// 判题程序
// Standard
// 作者
// CHEN, Yue
// 令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

// 输入格式：

// 输入在一行中给出M和N，其间以空格分隔。

// 输出格式：

// 输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

// 输入样例：
// 5 27
// 输出样例：
// 11 13 17 19 23 29 31 37 41 43
// 47 53 59 61 67 71 73 79 83 89
// 97 101 103