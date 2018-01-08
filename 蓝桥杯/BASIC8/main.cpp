#include <iostream>
using namespace std;
int main()
{
    for (int i = 1000; i < 10000; i++)
    {
        int qlw = i / 100;
        int a = qlw / 10;
        int b = qlw % 10;
        int qlwbh = b * 10 + a;
        int hlw = i % 100;
        if (qlwbh == hlw)
        {
            cout << i << endl;
        }
    }
    return 0;
}