// Date: Sun, 12 Dec 2021 02:14:00 +0000
// Language: C++17
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    while (true)
    {
        vector<i64> a(4);
        cin >> a[0] >> a[1] >> a[2] >> a[3];
        if (*max_element(a.begin(), a.end()) == 0)
        {
            break;
        }
        while (accumulate(a.begin(), a.end(), 0) - *max_element(a.begin(), a.end()) != 0)
        {
            sort(a.begin(), a.end(), [](auto const &l, auto const &r)
                 { return (l == 0 ? 1e9 : l) < (r == 0 ? 1e9 : r); });
            for (i64 i = 1; i < 4; i++)
            {
                if (a[i] != 0)
                {
                    a[i] -= a[0];
                }
            }
        }
        cout << *max_element(a.begin(), a.end()) << endl;
    }
    return 0;
}
