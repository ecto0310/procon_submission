// Date: Sat, 19 Nov 2022 12:57:54 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 H, W, N, h, w;
    cin >> H >> W >> N >> h >> w;
    vector<vector<i64>> A(H + 1, vector<i64>(W + 1));
    for (i64 i = 0; i < H; i++)
    {
        for (i64 j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }
    for (i64 i = 0; i <= H - h; i++)
    {
        vector<i64> count(N + 1);
        i64 ans = 0;
        for (i64 j = 0; j < H; j++)
        {
            for (i64 k = 0; k < W; k++)
            {
                if (!(i <= j && j < i + h && k < w))
                {
                    count[A[j][k]]++;
                    if (count[A[j][k]] == 1)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << " ";
        for (i64 j = 0; j < W - w; j++)
        {
            for (i64 k = i; k < i + h; k++)
            {
                count[A[k][j]]++;
                if (count[A[k][j]] == 1)
                {
                    ans++;
                }
            }
            for (i64 k = i; k < i + h; k++)
            {
                count[A[k][j + w]]--;
                if (count[A[k][j + w]] == 0)
                {
                    ans--;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}
