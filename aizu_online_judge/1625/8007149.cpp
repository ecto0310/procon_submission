// Date: Thu, 29 Jun 2023 11:31:49 +0000
// Language: C++17
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

bool solve() {
  i64 n, m, t, p;
  cin >> n >> m >> t >> p;
  if (n == 0 && m == 0 && t == 0 && p == 0) {
    return false;
  }
  vector<vector<i64>> count(m * 2, vector<i64>(n * 2, 0));
  for (i64 i = 0; i < m; i++) {
    for (i64 j = 0; j < n; j++) {
      count[i][j] = 1;
    }
  }
  for (i64 _ = 0; _ < t; _++) {
    i64 d, c;
    cin >> d >> c;
    if (d == 1) {
      for (i64 i = 0; i < m; i++) {
        for (i64 j = 0; j < c; j++) {
          count[i][c * 2 - j - 1] += count[i][j];
          count[i][j] = 0;
        }
      }
      for (i64 i = 0; i < m * 2; i++) {
        for (i64 j = 0; j < n * 2; j++) {
          if (2 * n <= j + c) {
            count[i][j] = 0;
          } else {
            count[i][j] = count[i][j + c];
          }
        }
      }
    } else {
      for (i64 i = 0; i < c; i++) {
        for (i64 j = 0; j < n; j++) {
          count[c * 2 - i - 1][j] += count[i][j];
          count[i][j] = 0;
        }
      }
      for (i64 i = 0; i < m * 2; i++) {
        for (i64 j = 0; j < n * 2; j++) {
          if (2 * m <= i + c) {
            count[i][j] = 0;
          } else {
            count[i][j] = count[i + c][j];
          }
        }
      }
    }
  }
  for (i64 _ = 0; _ < p; _++) {
    i64 x, y;
    cin >> x >> y;
    cout << count[y][x] << endl;
  }
  return true;
}

int main() {
  while (solve())
    ;
  return 0;
}
