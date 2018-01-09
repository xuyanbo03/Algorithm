#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len = s.length();
    long long sum = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'F')
        {
            sum += (s[i] - 'A' + 10) * pow(16, len - 1 - i);
        }
        else
        {
            sum += (s[i] - '0') * pow(16, len - 1 - i);
        }
    }
    cout << sum;
    return 0;
}