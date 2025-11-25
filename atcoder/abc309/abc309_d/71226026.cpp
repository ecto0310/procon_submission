// Date: Tue, 25 Nov 2025 11:52:53 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N1, N2, M;
  cin >> N1 >> N2 >> M;
  vector<vector<ll>> edges(N1 + N2 + 1);
  for (ll i = 0; i < M; i++) {
    ll u, v;
    cin >> u >> v;
    edges[u].push_back(v);
    edges[v].push_back(u);
  }
  auto longest_dist = [&](ll start) -> ll {
    ll max_dist = 0;
    vector<ll> dist(N1 + N2 + 1, -1);
    dist[start] = 0;
    queue<ll> q;
    q.push(start);
    while (!q.empty()) {
      ll curr = q.front();
      q.pop();
      for (ll next : edges[curr]) {
        if (dist[curr] + 1 < dist[next] || dist[next] == -1) {
          dist[next] = dist[curr] + 1;
          q.push(next);
          if (dist[next] > max_dist) {
            max_dist = dist[next];
          }
        }
      }
    }
    return max_dist;
  };
  cout << longest_dist(1) + longest_dist(N1 + N2) + 1 << endl;

  return 0;
}
