// Date: Sat, 13 Nov 2021 12:50:15 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 N;
    cin >> N;
    i64 ans = 0;
    for (i64 i = 1; i * i <= N; i++)
    {
        for (i64 j = i; 0 < N / (i * j) - j + 1; j++)
        {
            ans += N / (i * j) - j + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
