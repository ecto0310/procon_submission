// Date: Sat, 27 May 2023 12:20:49 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N, M;
  cin >> N >> M;
  vector<vector<i64>> a(M, vector<i64>(N));
  for (i64 i = 0; i < M; i++) {
    for (i64 j = 0; j < N; j++) {
      cin >> a[i][j];
      a[i][j]--;
    }
  }
  vector<set<i64>> s(N);
  for (i64 i = 0; i < M; i++) {
    for (i64 j = 0; j < N; j++) {
      if (0 <= j - 1) {
        s[a[i][j]].insert(a[i][j - 1]);
      }
      if (j + 1 < N) {
        s[a[i][j]].insert(a[i][j + 1]);
      }
    }
  }
  i64 ans = N * (N - 1);
  for (i64 i = 0; i < N; i++) {
    ans -= s[i].size();
  }
  cout << ans / 2 << endl;
  return 0;
}
