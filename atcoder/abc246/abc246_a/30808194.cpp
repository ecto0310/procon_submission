// Date: Sat, 09 Apr 2022 12:04:08 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    int x[3], y[3];
    for (i64 i = 0; i < 3; i++)
    {
        cin >> x[i] >> y[i];
    }
    for (i64 i = 0; i < 3; i++)
    {
        for (i64 j = i + 1; j < 3; j++)
        {
            if (x[i] == x[j])
            {
                cout << x[3 - i - j] << " ";
            }
        }
    }
    for (i64 i = 0; i < 3; i++)
    {
        for (i64 j = i + 1; j < 3; j++)
        {
            if (y[i] == y[j])
            {
                cout << y[3 - i - j] << endl;
            }
        }
    }

    return 0;
}
