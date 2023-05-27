// Date: Sat, 27 May 2023 12:28:02 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N, M, H, K;
  cin >> N >> M >> H >> K;
  string S;
  cin >> S;
  set<pair<i64, i64>> s;
  for (i64 i = 0; i < M; i++) {
    i64 x, y;
    cin >> x >> y;
    s.insert({x, y});
  }
  i64 x = 0, y = 0;
  for (char i : S) {
    if (i == 'R') {
      x++;
    }
    if (i == 'L') {
      x--;
    }
    if (i == 'U') {
      y++;
    }
    if (i == 'D') {
      y--;
    }
    H--;
    if (H < 0) {
      cout << "No" << endl;
      return 0;
    }
    if (s.count({x, y}) == 1 && H < K) {
      s.erase({x, y});
      H = K;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
