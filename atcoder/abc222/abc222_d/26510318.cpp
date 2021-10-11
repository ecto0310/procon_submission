// Date: Mon, 11 Oct 2021 13:46:04 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MOD = 998244353;

int main()
{
    i64 N;
    cin >> N;
    vector<i64> a(N), b(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (i64 i = 0; i < N; i++)
    {
        cin >> b[i];
    }
    vector<vector<i64>> dp(2, vector<i64>(3001));
    dp[0][0] = 1;
    for (i64 i = 0; i < N; i++)
    {
        for (i64 j = 0; j < 3000; j++)
        {
            (dp[i & 1][j + 1] += dp[i & 1][j]) %= MOD;
        }
        dp[(i + 1) & 1] = vector<i64>(3001);
        for (i64 j = a[i]; j <= b[i]; j++)
        {
            (dp[(i + 1) & 1][j] = dp[i & 1][j]) %= MOD;
        }
    }
    for (i64 j = 0; j < 3000; j++)
    {
        (dp[N & 1][j + 1] += dp[N & 1][j]) %= MOD;
    }
    cout << dp[N & 1][3000] % MOD << endl;
    return 0;
}
