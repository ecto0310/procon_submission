// Date: Sat, 13 Nov 2021 12:48:23 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N;
    cin >> N;
    i64 ans = 0;
    for (i64 i = 1; i <= N; i++)
    {
        if (N < i * i)
        {
            break;
        }
        for (i64 j = i; i * j <= N; j++)
        {
            if (N / (i * j) - j + 1 <= 0)
            {
                break;
            }
            ans += N / (i * j) - j + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
