// Date: Sun, 09 Apr 2023 12:01:49 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define debug(expr) cerr << #expr " = " << (expr) << '\n';
#else
#define debug(...)
#endif

using namespace std;
using i64 = int64_t;

int main() {
  i64 N, D;
  cin >> N >> D;
  vector<i64> T(N);
  for (i64 &i : T) {
    cin >> i;
  }
  for (i64 i = 0; i < N - 1; i++) {
    if (T[i + 1] - T[i] <= D) {
      cout << T[i + 1] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
