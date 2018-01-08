#include <iostream>
using namespace std;
int main()
{
    for (int i = 100; i < 1000; i++)
    {
        int bw = i / 100;
        int sw = i / 10 % 10;
        int gw = i % 100 % 10;
        if (bw * bw * bw + sw * sw * sw + gw * gw * gw == i)
        {
            cout << i << endl;
        }
    }
    return 0;
}