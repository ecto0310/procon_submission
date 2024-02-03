// Date: Sat, 03 Feb 2024 12:10:45 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll H, W, N;
  cin >> H >> W >> N;
  vector<string> S(H, string(W, '.'));
  ll pos_x = 0, pos_y = 0, d = 0;
  ll dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
  for (ll i = 0; i < N; i++) {
    if (S[pos_x][pos_y] == '.') {
      S[pos_x][pos_y] = '#';
      d = (d + 1) % 4;
    } else {
      S[pos_x][pos_y] = '.';
      d = (d + 3) % 4;
    }
    pos_x = (dx[d] + pos_x + H) % H;
    pos_y = (dy[d] + pos_y + W) % W;
  }
  for (string i : S) {
    cout << i << endl;
  }
  return 0;
}
