// Date: Sun, 27 Aug 2023 09:07:10 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
  ll N, M;
  cin >> N >> M;
  vector<vector<pair<ll, ll>>> edge(N);
  for (ll i = 0; i < M; i++) {
    ll A, B, C;
    cin >> A >> B >> C;
    A--;
    B--;
    edge[A].push_back({B, C});
    edge[B].push_back({A, C});
  }
  vector<bool> vis(N);
  auto dfs = [&](auto self, ll count, ll now, ll now_c) -> ll {
    vis[now] = true;
    ll m = now_c;
    for (auto [to, c] : edge[now]) {
      if (!vis[to]) {
        m = max(m, self(self, count - 1, to, now_c + c));
      }
    }
    vis[now] = false;
    return m;
  };
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ans = max(ans, dfs(dfs, N - 1, i, 0));
  }
  cout << ans << endl;
  return 0;
}
