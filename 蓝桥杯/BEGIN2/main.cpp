#include <iostream>
#include <cstdio>
using namespace std;
#define LINT long long

int main()
{
    LINT n;
    cin >> n;
    LINT sum = 0;
    sum = n * (n + 1) / 2;
    printf("%I64d", sum);
    return 0;
}