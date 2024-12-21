// Date: Sat, 21 Dec 2024 14:03:13 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<vector<ll>> edge(N);
  for (ll i = 0; i < N - 1; i++) {
    ll u, v;
    cin >> u >> v;
    u--;
    v--;
    edge[u].push_back(v);
    edge[v].push_back(u);
  }
  ll ans = N - 3;
  for (ll i = 0; i < N; i++) {
    sort(edge[i].begin(), edge[i].end(), [&](auto const& lhs, auto const& rhs) {
      return edge[rhs].size() < edge[lhs].size();
    });
    ll x = 0;
    for (ll j : edge[i]) {
      x++;
      ans = min(ans, N - (1 + x + x * ((ll)edge[j].size() - 1)));
    }
  }
  cout << ans << endl;
  return 0;
}
