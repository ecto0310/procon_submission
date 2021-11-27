// Date: Sat, 27 Nov 2021 12:16:00 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N, W;
    cin >> N >> W;
    vector<pair<i64, i64>> C(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> C[i].first >> C[i].second;
    }
    i64 ans = 0;
    sort(C.rbegin(), C.rend());
    for (i64 i = 0; i < N; i++)
    {
        i64 u = min(W, C[i].second);
        ans += C[i].first * u;
        W -= u;
    }
    cout << ans << endl;
    return 0;
}
