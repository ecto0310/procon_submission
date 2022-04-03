// Date: Sun, 03 Apr 2022 01:05:28 +0000
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
    i64 ans = LLONG_MAX, b = 1e6;
    for (i64 a = 0; a <= 1e6; a++)
    {
        while (N <= f(a, b) && 0 <= b)
        {
            ans = min(ans, f(a, b));
            b--;
        }
    }
    cout << ans << endl;
    return 0;
}
