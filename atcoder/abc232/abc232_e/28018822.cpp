// Date: Sun, 19 Dec 2021 13:46:36 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MOD = 998244353;

int main()
{
    i64 H, W, K, x[2], y[2];
    cin >> H >> W >> K >> x[0] >> y[0] >> x[1] >> y[1];
    i64 dp[2][2][2] = {};
    dp[0][(x[0] == x[1] ? 0 : 1)][(y[0] == y[1] ? 0 : 1)] = 1;
    for (i64 i = 0; i < K; i++)
    {
        dp[(i + 1) & 1][0][0] = (dp[i & 1][1][0] + dp[i & 1][0][1]) % MOD;
        dp[(i + 1) & 1][0][1] = (dp[i & 1][1][1] + dp[i & 1][0][0] * (W - 1) % MOD) % MOD;
        dp[(i + 1) & 1][1][1] = (dp[i & 1][0][1] * (H - 1) % MOD + dp[i & 1][1][0] * (W - 1) % MOD) % MOD;
        dp[(i + 1) & 1][1][0] = (dp[i & 1][0][0] * (H - 1) % MOD + dp[i & 1][1][1]) % MOD;
        if (3 <= H)
        {
            (dp[(i + 1) & 1][1][0] += dp[i & 1][1][0] * (H - 2) % MOD) %= MOD;
            (dp[(i + 1) & 1][1][1] += dp[i & 1][1][1] * (H - 2) % MOD) %= MOD;
        }
        if (3 <= W)
        {
            (dp[(i + 1) & 1][0][1] += dp[i & 1][0][1] * (W - 2) % MOD) %= MOD;
            (dp[(i + 1) & 1][1][1] += dp[i & 1][1][1] * (W - 2) % MOD) %= MOD;
        }
    }
    cout << dp[K & 1][0][0] << endl;
    return 0;
}
