// Date: Sat, 23 Apr 2022 12:21:24 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N;
    cin >> N;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<i64> count(200001);
    for (i64 i = 0; i < N; i++)
    {
        count[A[i]]++;
    }
    i64 ans = 0;
    for (i64 i = 1; i <= 200000; i++)
    {
        for (i64 j = 1; j * i <= 200000; j++)
        {
            ans += count[i] * count[j] * count[i * j];
        }
    }
    cout << ans << endl;
    return 0;
}
