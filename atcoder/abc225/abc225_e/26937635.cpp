// Date: Sat, 30 Oct 2021 15:20:22 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N;
    cin >> N;
    vector<pair<i64, i64>> p(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin(), p.end(), [](const pair<i64, i64> &l, const pair<i64, i64> &r)
         { return l.first * (r.second - 1) - (l.second - 1) * r.first < 0; });
    i64 ans = 0, it = -1;
    for (i64 i = 0; i < N; i++)
    {
        if (it == -1 || 0 <= (p[i].first - 1) * (p[it].second - 1) - p[i].second * p[it].first)
        {
            ans++;
            it = i;
        }
    }
    cout << ans << endl;
    return 0;
}
