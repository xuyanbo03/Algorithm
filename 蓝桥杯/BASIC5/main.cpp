#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int sl[n];
    for (int i = 0; i < n; i++)
    {
        cin >> sl[i];
    }
    int a;
    cin >> a;
    int i;
    for (i = 0; i < n; i++)
    {
        if (sl[i] == a)
        {
            break;
        }
    }
    if (i == n)
    {
        cout << "-1";
    }
    else
    {
        cout << i + 1;
    }
    return 0;
}