// Date: Sat, 06 Jan 2024 12:17:16 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<vector<string>> S(N, vector<string>(N, ""));
  S[N / 2][N / 2] = "T";
  ll dx[4] = {1, 0, -1, 0};
  ll dy[4] = {0, 1, 0, -1};
  ll x = 0, y = 0, t = 0;
  for (ll i = 1; i <= N * N - 1; i++) {
    S[x][y] = to_string(i);
    ll tx = x + dx[t], ty = y + dy[t];
    if (tx < 0 || N <= tx || ty < 0 || N <= ty || S[tx][ty] != "") {
      t = (t + 1) % 4;
    }
    x += dx[t];
    y += dy[t];
  }
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      cout << S[i][j] << " \n"[j + 1 == N];
    }
  }
  return 0;
}
