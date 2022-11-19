// Date: Sat, 19 Nov 2022 12:07:11 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 H, M;
    cin >> H >> M;
    for (i64 i = H; i < 24; i++)
    {
        for (i64 j = (i == H ? M : 0); j < 60; j++)
        {
            i64 h = i / 10 * 10 + j / 10;
            i64 m = i % 10 * 10 + j % 10;
            if (0 <= h && h <= 23 && 0 <= m && m <= 59)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    for (i64 i = 0; i < 24; i++)
    {
        for (i64 j = 0; j < 60; j++)
        {
            i64 h = i / 10 * 10 + j / 10;
            i64 m = i % 10 * 10 + j % 10;
            if (0 <= h && h <= 23 && 0 <= m && m <= 59)
            {
                cout << i << " " << j << endl;
                return 0;
            }
        }
    }
    return 0;
}
