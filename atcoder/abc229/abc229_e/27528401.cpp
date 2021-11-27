// Date: Sat, 27 Nov 2021 12:23:01 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

struct UnionFind
{
    vector<int> data;

    UnionFind(int sz)
    {
        data.assign(sz, -1);
    }

    bool unite(int x, int y)
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

    int find(int k)
    {
        if (data[k] < 0)
            return (k);
        return (data[k] = find(data[k]));
    }

    int size(int k)
    {
        return (-data[find(k)]);
    }
};

int main()
{
    i64 N, M;
    cin >> N >> M;
    vector<i64> edge[N];
    for (i64 i = 0; i < M; i++)
    {
        i64 A, B;
        cin >> A >> B;
        A--;
        B--;
        edge[min(A, B)].push_back(max(A, B));
    }
    UnionFind uf(N);
    vector<i64> ans(N + 1);
    for (i64 i = N - 1; 0 <= i; i--)
    {
        ans[i] = ans[i + 1] + 1;
        for (i64 j : edge[i])
        {
            if (uf.unite(i, j))
            {
                ans[i]--;
            }
        }
    }
    for (i64 i = 1; i <= N; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
