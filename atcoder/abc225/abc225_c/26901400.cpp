// Date: Sat, 30 Oct 2021 12:16:18 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N, M;
    cin >> N >> M;
    vector<vector<i64>> B(N, vector<i64>(M));
    for (i64 i = 0; i < N; i++)
    {
        for (i64 j = 0; j < M; j++)
        {
            cin >> B[i][j];
        }
    }
    for (i64 i = 0; i < N; i++)
    {
        for (i64 j = 0; j < M; j++)
        {
            if (B[0][0] + 7 * i + j != B[i][j])
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    if ((B[0][M - 1] - 1) % 7 < (B[0][0] - 1) % 7)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
    }
    return 0;
}
