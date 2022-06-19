// Date: Sun, 19 Jun 2022 12:00:34 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N;
    cin >> N;
    i64 ans = 1;
    for (int i = 0; i < N; i++)
    {
        ans *= 2;
    }
    cout << ans << endl;
    return 0;
}
