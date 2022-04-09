// Date: Sat, 09 Apr 2022 12:30:03 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

i64 f(i64 a, i64 b)
{
    return a * a * a + a * a * b + a * b * b + b * b * b;
}

int main()
{
    i64 N;
    cin >> N;
    i64 j = 1e6;
    i64 ans = LONG_LONG_MAX;
    for (i64 i = 0; i <= 1e6; i++)
    {
        while (0 <= j && N <= f(i, j))
        {
            ans = min(ans, f(i, j));
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}
