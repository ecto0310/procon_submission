// Date: Sat, 23 Oct 2021 13:38:47 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

int main()
{
    i64 M;
    cin >> M;
    vector<i64> edge[9];
    for (i64 i = 0; i < M; i++)
    {
        i64 u, v;
        cin >> u >> v;
        u--;
        v--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    vector<i64> tmp(9, -1), valid(9, -1);
    for (i64 i = 0; i < 8; i++)
    {
        i64 t;
        cin >> t;
        tmp[t - 1] = i;
        valid[i] = i;
    }
    map<vector<i64>, i64> s;
    priority_queue<pair<i64, vector<i64>>, vector<pair<i64, vector<i64>>>, greater<pair<i64, vector<i64>>>> que;
    s[tmp] = 1;
    que.push({1, tmp});
    while (que.size())
    {
        pair<i64, vector<i64>> p = que.top();
        que.pop();
        if (s[p.second] < p.first)
        {
            continue;
        }
        if (p.second == valid)
        {
            cout << p.first - 1 << endl;
            return 0;
        }
        i64 t = find(p.second.begin(), p.second.end(), -1) - p.second.begin();
        vector<i64> l = p.second;
        for (i64 i : edge[t])
        {
            swap(l[i], l[t]);
            if (s[p.second] + 1 < s[l] || s[l] == 0)
            {
                s[l] = s[p.second] + 1;
                que.push({s[l], l});
            }
            swap(l[i], l[t]);
        }
    }
    cout << -1 << endl;
    return 0;
}
