// Date: Mon, 11 Oct 2021 05:12:27 +0000
// Language: C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    while (true)
    {
        i64 m, n, p;
        cin >> m >> n >> p;
        if (m == 0 && n == 0 & p == 0)
        {
            break;
        }
        vector<bool> t(m + 1);
        t[p] = true;
        for (i64 i = 0; i < n; i++)
        {
            i64 a, b;
            cin >> a >> b;
            if (t[a] || t[b])
            {
                t[a] = t[b] = true;
            }
        }
        i64 ans = count_if(t.begin(), t.end(), [](bool x)
                           { return x; });
        cout << ans << endl;
    }
    return 0;
}
