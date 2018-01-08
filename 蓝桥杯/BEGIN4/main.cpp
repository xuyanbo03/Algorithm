#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int f[n];
    f[1] = f[2] = 1;
    int result = 1;
    for (int i = 3; i <= n; i++)
    {
        f[i] = (f[i - 1] + f[i - 2]) % 10007;
    }
    result = f[n];
    cout << result;
    return 0;
}