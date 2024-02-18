// Date: Sun, 18 Feb 2024 02:50:57 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll H, W, N;
  string T;
  cin >> H >> W >> N >> T;
  vector<string> S(H);
  for (string &i : S) {
    cin >> i;
  }
  ll ans = 0;
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      if (S[i][j] == '#') {
        continue;
      }
      bool ok = true;
      ll h = i, w = j;
      for (char k : T) {
        if (k == 'L') {
          w--;
        } else if (k == 'R') {
          w++;
        } else if (k == 'U') {
          h--;
        } else {
          h++;
        }
        if (S[h][w] == '#') {
          ok = false;
          break;
        }
      }
      if (ok) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
