// Date: Sun, 19 Jun 2022 12:33:43 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N;
    cin >> N;
    vector<pair<i64, i64>> P(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> P[i].first >> P[i].second;
    }
    sort(P.begin(), P.end());
    cout << P[0].first << " ";
    i64 m = 0;
    for (i64 i = 0; i < N - 1; i++)
    {
        m = max(m, P[i].second);
        if (m < P[i + 1].first)
        {
            cout << m << endl
                 << P[i + 1].first << " ";
        }
    }
    cout << max(m, P[N - 1].second) << endl;
    return 0;
}
