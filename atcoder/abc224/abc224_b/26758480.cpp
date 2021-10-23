// Date: Sat, 23 Oct 2021 12:05:29 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 H, W;
    cin >> H >> W;
    vector<vector<i64>> A(H, vector<i64>(W));
    for (i64 i = 0; i < H; i++)
    {
        for (i64 j = 0; j < W; j++)
        {
            cin >> A[i][j];
        }
    }
    for (i64 i1 = 0; i1 < H; i1++)
    {
        for (i64 i2 = i1 + 1; i2 < H; i2++)
        {
            for (i64 j1 = 0; j1 < W; j1++)
            {
                for (i64 j2 = j1 + 1; j2 < W; j2++)
                {
                    if (A[i2][j1] + A[i1][j2] < A[i1][j1] + A[i2][j2])
                    {
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}
