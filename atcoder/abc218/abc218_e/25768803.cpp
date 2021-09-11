// Date: Sat, 11 Sep 2021 12:45:12 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct UnionFind
{
    vector<i64> data;

    UnionFind(i64 sz)
    {
        data.assign(sz, -1);
    }

    bool unite(i64 x, i64 y)
    {
        x = find(x), y = find(y);
        if (x == y)
            return (false);
        if (data[x] > data[y])
            swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    bool check(i64 x, i64 y)
    {
        x = find(x), y = find(y);
        return x == y;
    }

    i64 find(i64 k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }
};

int main()
{
    i64 N, M;
    cin >> N >> M;
    vector<pair<i64, pair<i64, i64>>> E(M);
    for (i64 i = 0; i < M; i++)
    {
        cin >> E[i].second.first >> E[i].second.second >> E[i].first;
    }
    sort(E.begin(), E.end());
    UnionFind uf(N);
    i64 ans = 0;
    for (i64 i = 0; i < M; i++)
    {
        bool m = uf.check(E[i].second.first - 1, E[i].second.second - 1);
        if (m && 0 <= E[i].first)
        {
            ans += E[i].first;
        }
        else
        {
            uf.unite(E[i].second.first - 1, E[i].second.second - 1);
        }
    }
    cout << ans << endl;
    return 0;
}
