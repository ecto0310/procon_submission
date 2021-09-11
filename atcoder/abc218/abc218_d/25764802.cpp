// Date: Sat, 11 Sep 2021 12:32:43 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

bool out(i64 x, i64 N)
{
    return 0 <= x && x < N;
}

int main()
{
    i64 N;
    cin >> N;
    vector<i64> x(N), y(N);
    map<pair<i64, i64>, bool> p;
    for (i64 i = 0; i < N; i++)
    {
        cin >> x[i] >> y[i];
        p[{x[i], y[i]}] = true;
    }
    i64 ans = 0;
    for (i64 i = 0; i < N; i++)
    {
        for (i64 j = i + 1; j < N; j++)
        {
            if (x[i] == x[j] || y[i] == y[j])
            {
                continue;
            }
            if (p[{x[i], y[j]}] && p[{x[j], y[i]}])
            {
                ans++;
            }
        }
    }
    cout << ans / 2 << endl;
    return 0;
}
