// Date: Sun, 19 Dec 2021 12:25:57 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 H, W;
    cin >> H >> W;
    vector<string> C(H);
    for (i64 i = 0; i < H; i++)
    {
        cin >> C[i];
    }
    vector<vector<i64>> dp(H, vector<i64>(W, 0));
    i64 ans = 0;
    dp[0][0] = 1;
    for (i64 i = 0; i < H; i++)
    {
        for (i64 j = 0; j < W; j++)
        {
            if (dp[i][j] == 0)
            {
                continue;
            }
            if (j + 1 != W && C[i][j + 1] == '.')
            {
                dp[i][j + 1] = max(dp[i][j + 1], dp[i][j] + 1);
            }
            if (i + 1 != H && C[i + 1][j] == '.')
            {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + 1);
            }
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
