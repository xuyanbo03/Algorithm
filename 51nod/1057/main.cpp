#include <iostream>
#include <cstdio>
#define mod 10000000000000
#define N 1000010
#define LL long long

using namespace std; 

LL num[N];

int main()
{
    LL i,j,n;
    LL k,ans,t;
    while(scanf("%lld",&n)!=EOF)
    {
        ans = 1;
        num[1] = 1;
        for(i = 1; i <= n; i++)
        {
            k = 0;
            for(j = 1; j <= ans; j++)
            {
                t = num[j] * i + k;
                num[j] = t % mod;
                k = t / mod;
            }
            if(k){
            	num[++ans] = k;
			}
        }
        printf("%lld",num[ans]);
        
        for(i = ans-1; i >= 1; i--){
        	printf("%013lld",num[i]);
		}
        printf("\n");
    }
    return 0;
}
