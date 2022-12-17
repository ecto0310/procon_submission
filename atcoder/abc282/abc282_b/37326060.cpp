// Date: Sat, 17 Dec 2022 12:03:28 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
  i64 N, M;
  cin >> N >> M;
  vector<string> S(N);
  for (i64 i = 0; i < N; i++) {
    cin >> S[i];
  }
  i64 ans = 0;
  for (i64 i = 0; i < N; i++) {
    for (i64 j = i + 1; j < N; j++) {
      bool ok = true;
      for (i64 k = 0; k < M; k++) {
        if (S[i][k] == 'x' && S[j][k] == 'x') {
          ok = false;
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
