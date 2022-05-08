// Date: Sun, 08 May 2022 12:02:55 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 H, W, R, C;
    cin >> H >> W >> R >> C;
    int ans = 4;
    if (R == 1)
    {
        ans--;
    }
    if (R == H)
    {
        ans--;
    }
    if (C == 1)
    {
        ans--;
    }
    if (C == W)
    {
        ans--;
    }
    cout << ans << endl;
    return 0;
}
