// Date: Sat, 14 Dec 2024 12:49:57 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

ll dh[4] = {1, -1, 0, 0};
ll dw[4] = {0, 0, 1, -1};

int main() {
  ll H, W, X;
  cin >> H >> W >> X;
  ll P, Q;
  cin >> P >> Q;
  P--;
  Q--;
  vector<vector<ll>> S(H, vector<ll>(W));
  for (vector<ll> &i : S) {
    for (ll &j : i) {
      cin >> j;
    }
  }
  vector<vector<bool>> use(H, vector<bool>(W));
  auto is_gird = [&](ll h, ll w) {
    return (0 <= h && h < H && 0 <= w && w < W);
  };
  priority_queue<pair<ll, pair<ll, ll>>, vector<pair<ll, pair<ll, ll>>>,
                 greater<pair<ll, pair<ll, ll>>>>
      que;
  vector<vector<bool>> add(H, vector<bool>(W));
  ll p = S[P][Q];
  use[P][Q] = true;
  add[P][Q] = true;
  for (ll i = 0; i < 4; i++) {
    ll ah = P + dh[i];
    ll aw = Q + dw[i];
    if (!is_gird(ah, aw)) {
      continue;
    }
    use[ah][aw] = true;
    que.push({S[ah][aw], {ah, aw}});
  }
  while (!que.empty()) {
    auto [s, pos] = que.top();
    auto [nh, nw] = pos;
    que.pop();
    if (S[nh][nw] < (p + X - 1) / X && !add[nh][nw]) {
      p += S[nh][nw];
      add[nh][nw] = true;
      for (ll i = 0; i < 4; i++) {
        ll ah = nh + dh[i];
        ll aw = nw + dw[i];
        if (!is_gird(ah, aw) || use[ah][aw]) {
          continue;
        }
        use[nh][nw] = true;
        que.push({S[ah][aw], {ah, aw}});
      }
    }
  }
  cout << p << endl;
  return 0;
}
