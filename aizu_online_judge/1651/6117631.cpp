// Date: Sun, 12 Dec 2021 02:16:36 +0000
// Language: C++17
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    while (true)
    {
        i64 n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        vector<i64> b(n);
        for (i64 i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<vector<vector<i64>>> dp(2, vector<vector<i64>>(900, vector<i64>(900, -1)));
        dp[0][0][0] = 0;
        for (i64 i = 0; i < n; i++)
        {
            for (i64 j = 0; j < 850; j++)
            {
                for (i64 k = 0; k < 850; k++)
                {
                    if (dp[i&1][j][k] == -1)
                    {
                        continue;
                    }
                    dp[(i + 1)&1][j + b[i]][k] = dp[i&1][j][k];
                    dp[(i + 1)&1][j][k + b[i]] = dp[i&1][j][k];
                    dp[(i + 1)&1][j][k] = dp[i&1][j][k] + b[i];
                }
            }
        }
        i64 ans = 0;
        for (i64 j = 0; j < 850; j++)
        {
            for (i64 k = 0; k < 850; k++)
            {
                ans = max(ans, min({j, k, dp[n&1][j][k]}));
            }
        }
        cout << ans << endl;
    }
    return 0;
}
