#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int t1 = 1; t1 < 10; t1++)
    {
        for (int t2 = 0; t2 < 10; t2++)
        {
            for (int t3 = 0; t3 < 10; t3++)
            {
                if (t1 + t2 + t3 + t2 + t1 == n)
                {
                    cout << t1 << t2 << t3 << t2 << t1 << endl;
                }
            }
        }
    }
    for (int t1 = 1; t1 < 10; t1++)
    {
        for (int t2 = 0; t2 < 10; t2++)
        {
            for (int t3 = 0; t3 < 10; t3++)
            {
                if (t1 + t2 + t3 + t3 + t2 + t1 == n)
                {
                    cout << t1 << t2 << t3 << t3 << t2 << t1 << endl;
                }
            }
        }
    }
    return 0;
}