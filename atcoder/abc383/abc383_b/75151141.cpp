// Date: Tue, 21 Apr 2026 11:21:24 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll H, W, D;
  cin >> H >> W >> D;
  vector<string> S(H);
  for (int i = 0; i < H; i++) {
    cin >> S[i];
  }
  auto calc = [&](vector<pair<ll, ll>>& pos) -> ll {
    set<pair<ll, ll>> count;
    for (ll i = 0; i < H; i++) {
      for (ll j = 0; j < W; j++) {
        if (S[i][j] == '#') {
          continue;
        }
        for (auto [x, y] : pos) {
          if (abs(i - x) + abs(j - y) <= D) {
            count.insert({i, j});
          }
        }
      }
    }
    return count.size();
  };

  ll ans = 0;
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      for (ll k = 0; k < H; k++) {
        for (ll l = 0; l < W; l++) {
          if (S[i][j] == '#' || S[k][l] == '#') {
            continue;
          }
          vector<pair<ll, ll>> pos = {{i, j}, {k, l}};
          ans = max(ans, calc(pos));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
