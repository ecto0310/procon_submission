// Date: Sat, 27 Apr 2024 17:39:37 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll dh[] = {0, 0, 1, -1};
const ll dw[] = {1, -1, 0, 0};

int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> S(H);
  for (string& i : S) {
    cin >> i;
  }
  ll ans = 1;
  vector<vector<ll>> used(H, vector<ll>(W, -1));
  for (ll sh = 0; sh < H; sh++) {
    for (ll sw = 0; sw < W; sw++) {
      ll now = sh * W + sw;
      bool sm = true;
      for (ll i = 0; i < 4; i++) {
        ll next_h = sh + dh[i];
        ll next_w = sw + dw[i];
        if (clamp(next_h, 0LL, H - 1) == next_h &&
            clamp(next_w, 0LL, W - 1) == next_w && S[next_h][next_w] == '#') {
          sm = false;
        }
      }
      if (!sm || used[sh][sw] != -1 || S[sh][sw] == '#') {
        continue;
      }
      queue<pair<ll, ll>> que;
      que.push({sh, sw});
      ll cnt = 0;
      used[sh][sw] = now;
      while (que.size()) {
        auto [now_h, now_w] = que.front();
        que.pop();
        cnt++;
        bool m = true;
        for (ll i = 0; i < 4; i++) {
          ll next_h = now_h + dh[i];
          ll next_w = now_w + dw[i];
          if (clamp(next_h, 0LL, H - 1) == next_h &&
              clamp(next_w, 0LL, W - 1) == next_w && S[next_h][next_w] == '#') {
            m = false;
          }
        }
        if (!m) {
          continue;
        }
        for (ll i = 0; i < 4; i++) {
          ll next_h = now_h + dh[i];
          ll next_w = now_w + dw[i];
          if (clamp(next_h, 0LL, H - 1) == next_h &&
              clamp(next_w, 0LL, W - 1) == next_w &&
              used[next_h][next_w] != now) {
            used[next_h][next_w] = now;
            que.push({next_h, next_w});
          }
        }
      }
      ans = max(ans, cnt);
    }
  }
  cout << ans << endl;
  return 0;
}
