// Date: Sat, 22 Jul 2023 16:28:29 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

#ifdef LOCAL
#define cerr cerr << "\033[31m"
#define cout cout << "\033[32m"
#define endl "\033[m" << endl
#endif

int main() {
  ll N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (ll i = 0; i < N; i++) {
    cin >> S[i];
  }
  vector<vector<vector<bool>>> m(N, vector<vector<bool>>(M, vector<bool>(4)));
  ll dx[4] = {1, -1, 0, 0};
  ll dy[4] = {0, 0, 1, -1};
  set<pair<ll, ll>> ans;
  ans.insert({1, 1});
  auto dfs = [&](auto self, ll x, ll y) -> void {
    for (ll i = 0; i < 4; i++) {
      if (m[x][y][i]) {
        continue;
      }
      m[x][y][i] = true;
      ll nx = x, ny = y;
      set<pair<ll, ll>> u;
      while (S[nx + dx[i]][ny + dy[i]] != '#') {
        nx += dx[i];
        ny += dy[i];
        ans.insert({nx, ny});
      }
      self(self, nx, ny);
      for (pair<ll, ll> p : u) {
        S[p.first][p.second] = '.';
      }
    }
    return;
  };
  dfs(dfs, 1, 1);
  cout << ans.size() << endl;
  return 0;
}
