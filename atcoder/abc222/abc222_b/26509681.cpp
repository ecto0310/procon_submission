// Date: Mon, 11 Oct 2021 13:16:49 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N, P;
    cin >> N >> P;
    vector<i64> a(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    i64 ans = 0;
    for (i64 i = 0; i < N; i++)
    {
        if (a[i] < P)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
