// Date: Tue, 21 Jun 2022 03:06:59 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 X, A, D, N;
    cin >> X >> A >> D >> N;
    if (D < 0)
    {
        A = A + D * (N - 1);
        D = -D;
    }
    i64 left = -1, right = N;
    while (1 < right - left)
    {
        i64 mid = (right - left) / 2 + left;
        if (A + D * mid < X)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    i64 ans = 2e18;
    if (0 <= left)
    {
        ans = min(ans, abs(A + D * left - X));
    }
    if (right < N)
    {
        ans = min(ans, abs(A + D * right - X));
    }
    cout << ans << endl;
    return 0;
}
