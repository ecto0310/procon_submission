// Date: Mon, 11 Oct 2021 04:48:15 +0000
// Language: C++17
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == 0)
        {
            break;
        }
        vector<i64> d(n);
        for (i64 i = 0; i < n; i++)
        {
            cin >> d[i];
        }
        i64 ans = 0;
        for (i64 i = 0; i < n - 3; i++)
        {
            if (d[i] == 2 && d[i + 1] == 0 && d[i + 2] == 2 && d[i + 3] == 0)
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
