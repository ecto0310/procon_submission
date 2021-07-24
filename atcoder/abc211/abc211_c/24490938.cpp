// Date: Sat, 24 Jul 2021 12:08:21 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

const i64 MOD = 1e9 + 7;

int main()
{
    string S;
    cin >> S;
    i64 size = S.size();
    vector<vector<i64>> dp(size + 1, vector<i64>(9, 0));
    dp[0][0] = 1;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (S[i] == "chokudai"[j])
            {
                (dp[i + 1][j + 1] += dp[i][j]) %= MOD;
            }
            (dp[i + 1][j] += dp[i][j]) %= MOD;
        }
        (dp[i + 1][8] += dp[i][8]) %= MOD;
    }
    cout << dp[size][8] << endl;
    return 0;
}
