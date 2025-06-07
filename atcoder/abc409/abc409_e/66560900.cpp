// Date: Sat, 07 Jun 2025 13:01:21 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> x(N);
  for (ll i = 0; i < N; i++) {
    cin >> x[i];
  }
  vector<vector<pair<ll, ll>>> g(N);
  for (ll i = 0; i < N - 1; i++) {
    ll u, v, w;
    cin >> u >> v >> w;
    g[u - 1].push_back({v - 1, w});
    g[v - 1].push_back({u - 1, w});
  }

  ll ans = 0;

  auto dfs = [&](auto dfs, ll u, ll p) -> ll {
    ll res = x[u];
    for (auto [v, w] : g[u]) {
      if (v == p) continue;
      ll sub = dfs(dfs, v, u);
      ans += abs(sub) * w;
      res += sub;
    }
    return res;
  };
  dfs(dfs, 0, -1);
  cout << ans << endl;

  return 0;
}
