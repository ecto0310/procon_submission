// Date: Sat, 09 Apr 2022 12:17:53 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N, K, X;
    cin >> N >> K >> X;
    vector<i64> A(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    priority_queue<i64> que;
    for (i64 i = 0; i < N; i++)
    {
        que.push(A[i]);
    }
    while (0 < K)
    {
        i64 a = que.top();
        if (a == 0)
        {
            break;
        }
        que.pop();
        i64 c = min(K, max(a / X, 1LL));
        a = max(0LL, a - c * X);
        que.push(a);
        K -= c;
    }
    i64 ans = 0;
    for (i64 i = 0; i < N; i++)
    {
        ans += que.top();
        que.pop();
    }
    cout << ans << endl;
    return 0;
}
