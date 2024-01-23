// Date: Tue, 23 Jan 2024 11:07:27 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll H, W, K;
  cin >> H >> W >> K;
  vector<string> S(H);
  for (ll i = 0; i < H; i++) {
    cin >> S[i];
  }
  ll ans = K + 1;
  for (ll i = 0; i < H; i++) {
    vector<ll> x_cnt(W + 1), dot_cnt(W + 1);
    x_cnt[1] = (S[i][0] == 'x' ? 1 : 0);
    dot_cnt[1] = (S[i][0] == '.' ? 1 : 0);
    for (ll j = 1; j < W; j++) {
      x_cnt[j + 1] = (S[i][j] == 'x' ? 1 : 0) + x_cnt[j];
      dot_cnt[j + 1] = (S[i][j] == '.' ? 1 : 0) + dot_cnt[j];
    }
    for (ll j = 0; j < W - K + 1; j++) {
      if (x_cnt[j] == x_cnt[j + K]) {
        ans = min(ans, dot_cnt[j + K] - dot_cnt[j]);
      }
    }
  }
  for (ll i = 0; i < W; i++) {
    vector<ll> x_cnt(H + 1), dot_cnt(H + 1);
    x_cnt[1] = (S[0][i] == 'x' ? 1 : 0);
    dot_cnt[1] = (S[0][i] == '.' ? 1 : 0);
    for (ll j = 1; j < H; j++) {
      x_cnt[j + 1] = (S[j][i] == 'x' ? 1 : 0) + x_cnt[j];
      dot_cnt[j + 1] = (S[j][i] == '.' ? 1 : 0) + dot_cnt[j];
    }
    for (ll j = 0; j < H - K + 1; j++) {
      if (x_cnt[j] == x_cnt[j + K]) {
        ans = min(ans, dot_cnt[j + K] - dot_cnt[j]);
      }
    }
  }
  if (ans == K + 1) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }
  return 0;
}
