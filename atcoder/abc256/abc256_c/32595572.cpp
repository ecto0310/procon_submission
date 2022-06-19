// Date: Sun, 19 Jun 2022 12:24:11 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

i64 calc(vector<vector<i64>> &ans, vector<i64> &h, vector<i64> &w, i64 now = 0)
{
    i64 ret = 0;
    if (now == 4)
    {
        for (i64 i = 0; i < 2; i++)
        {
            ans[2][i] = h[i] - ans[1][i] - ans[0][i];
            ans[i][2] = w[i] - ans[i][1] - ans[i][0];
            if (ans[2][i] <= 0 || ans[i][2] <= 0)
            {
                return 0;
            }
        }
        if (1 <= h[2] - ans[1][2] - ans[0][2] && h[2] - ans[1][2] - ans[0][2] == w[2] - ans[2][1] - ans[2][0])
        {
            return 1;
        }
        return 0;
    }
    for (i64 i = 1; i <= 30; i++)
    {
        ans[now % 2][now / 2] = i;
        ret += calc(ans, h, w, now + 1);
    }
    return ret;
}

int main()
{
    vector<i64> h(3), w(3);
    cin >> h[0] >> h[1] >> h[2] >> w[0] >> w[1] >> w[2];
    vector<vector<i64>> ans(3, vector<i64>(3));
    cout << calc(ans, h, w) << endl;
    return 0;
}
