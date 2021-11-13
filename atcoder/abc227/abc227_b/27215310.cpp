// Date: Sat, 13 Nov 2021 12:11:35 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N;
    cin >> N;
    vector<i64> S(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    set<i64> v;
    for (i64 i = 1; 3 * i <= 1000; i++)
    {
        for (i64 j = 1; 4 * i * j + 3 * i + 3 * j <= 1000; j++)
        {
            v.insert(4 * i * j + 3 * i + 3 * j);
        }
    }
    i64 ans = 0;
    for (i64 i : S)
    {
        if (v.count(i) == 0)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
