#include <iostream>
using namespace std;
int main()
{
    int a;
    cin >> a;
    int i = 0;
    char b[100];
    if (a == 0)
    {
        cout << 0;
    }
    else
    {
        while (a != 0)
        {
            if (a % 16 > 9)
            {
                b[i++] = a % 16 + 'A' - 10;
            }
            else
            {
                b[i++] = a % 16 + '0';
            }
            a = a / 16;
        }
    }
    for (int j = i - 1; j >= 0; j--)
    {
        cout << b[j];
    }
    return 0;
}