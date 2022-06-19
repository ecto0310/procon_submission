// Date: Sun, 19 Jun 2022 12:58:29 +0000
// Language: C++ (GCC 9.2.1)
					#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl '\n'

struct UnionFind
{
    vector<i64> par;
    UnionFind(i64 N) : par(N)
    {
        for (i64 i = 0; i < N; i++)
            par[i] = i;
    }

    i64 root(i64 x)
    {
        if (par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }

    bool merge(i64 x, i64 y)
    {
        i64 rx = root(x);
        i64 ry = root(y);
        if (rx == ry)
            return false;
        par[rx] = ry;
        return true;
    }

    bool same(i64 x, i64 y)
    {
        i64 rx = root(x);
        i64 ry = root(y);
        return rx == ry;
    }
};

int main()
{
    i64 N;
    cin >> N;
    vector<i64> X(N), C(N);
    for (i64 i = 0; i < N; i++)
    {
        cin >> X[i];
        X[i]--;
    }
    for (i64 i = 0; i < N; i++)
    {
        cin >> C[i];
    }
    i64 ans = 0;
    UnionFind uf(N);
    for (i64 i = 0; i < N; i++)
    {
        if (uf.merge(i, X[i]))
        {
            continue;
        }
        i64 now = i, m = C[i];
        do
        {
            now = X[now];
            m = min(m, C[now]);
        } while (now != i);
        ans += m;
    }
    cout << ans << endl;
    return 0;
}
