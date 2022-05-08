// Date: Sun, 08 May 2022 12:14:36 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

int main()
{
    i64 N, Q;
    cin >> N >> Q;
    vector<i64> ind(N), b(N);
    for (i64 i = 0; i < N; i++)
    {
        ind[i] = i;
        b[i] = i;
    }
    for (i64 i = 0; i < Q; i++)
    {
        i64 x;
        cin >> x;
        x--;
        x = ind[x];
        if (x == N - 1)
        {
            x--;
        }
        swap(b[x], b[x + 1]);
        swap(ind[b[x]], ind[b[x + 1]]);
    }
    for (i64 i = 0; i < N; i++)
    {
        cout << b[i] + 1 << " \n"[i + 1 == N];
    }
    return 0;
}
