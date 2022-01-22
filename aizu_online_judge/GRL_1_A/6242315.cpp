// Date: Sat, 22 Jan 2022 19:19:16 +0000
// Language: C++17
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
#define endl "\n"

using namespace std;
//頂点数
const int V = 100;
// 有向辺の行き先とコストの構造体
struct Edge
{
    int to, cost;
};
//未到達
const int INF = 1e9;
//グラフを表現する隣接リスト
vector<vector<Edge>> e(V);

vector<int> dijkstra(vector<vector<Edge>> &e, int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    vector<int> dist(e.size(), INF);
    dist[s] = 0;
    que.push({0, s});
    while (que.size())
    {
        auto [cost, now] = que.top();
        que.pop();
        if (dist[now] < cost)
        {
            continue;
        }
        for (auto i : e[now])
        {
            if (cost + i.cost < dist[i.to])
            {
                dist[i.to] = cost + i.cost;
                que.push({dist[i.to], i.to});
            }
        }
    }
    return dist;
}

vector<int> bellmanford(vector<vector<Edge>> &e, int s)
{
    int V = e.size();
    vector<int> dist(e.size(), INF);
    dist[s] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < V; j++)
        {
            for (auto k : e[j])
            {
                dist[k.to] = min(dist[k.to], dist[j] + k.cost);
            }
        }
    }
    for (int i = 0; i < V; i++)
    {
        for (auto j : e[i])
        {
            if (dist[i] + j.cost < dist[j.to])
            {
                return vector<int>();
            }
        }
    }
    return dist;
}

int main()
{
    int V, E, r;
    cin >> V >> E >> r;
    vector<vector<Edge>> e(V);
    for (int i = 0; i < E; i++)
    {
        int s, t, d;
        cin >> s >> t >> d;
        e[s].push_back({t, d});
    }
    vector<int> ans = dijkstra(e, r);
    for (int i : ans)
    {
        if (i == INF)
        {
            cout << "INF" << endl;
        }
        else
        {
            cout << i << endl;
        }
    }
    return 0;
}
