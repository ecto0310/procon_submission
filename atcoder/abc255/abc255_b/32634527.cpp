// Date: Tue, 21 Jun 2022 02:32:13 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N, K;
    cin >> N >> K;
    vector<i64> A(K);
    for (auto &i : A)
    {
        cin >> i;
        i--;
    }
    vector<pair<i64, i64>> P(N);
    for (auto &i : P)
    {
        cin >> i.first >> i.second;
    }
    P[0];
    double ans = 0;
    for (auto i : P)
    {
        double t = 1e8;
        for (auto j : A)
        {
            t = min(t, hypot(i.first - P[j].first, i.second - P[j].second));
        }
        ans = max(ans, t);
    }
    cout << fixed << setprecision(6) << ans << endl;
    return 0;
}
