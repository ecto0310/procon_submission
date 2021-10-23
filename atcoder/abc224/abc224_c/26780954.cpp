// Date: Sat, 23 Oct 2021 13:42:13 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N;
    cin >> N;
    vector<i64> X(N), Y(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> X[i] >> Y[i];
    }
    i64 ans = 0;
    for (i64 i = 0; i < N; i++)
    {
        for (i64 j = i + 1; j < N; j++)
        {
            for (i64 k = j + 1; k < N; k++)
            {
                i64 dx1 = X[k] - X[i], dy1 = Y[k] - Y[i];
                i64 dx2 = X[j] - X[i], dy2 = Y[j] - Y[i];
                if (dx1 * dy2 != dx2 * dy1)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
