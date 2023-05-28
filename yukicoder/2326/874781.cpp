// Date: Sun, 28 May 2023 15:12:18 +0000
// Language: C++17
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const i64 MOD = 1e9 + 7;

int main() {
  i64 N, P;
  cin >> N >> P;
  i64 count = 0;
  i64 prd = 1;
  for (i64 i = 1; i <= N; i++) {
    i64 t = i;
    while (0 < t && t % P == 0) {
      t /= P;
      count++;
      count %= MOD;
    }
    prd *= i;
    prd %= MOD;
  }
  auto p = [](i64 x, i64 n) {
    i64 ret = 1;
    while (0 < n) {
      if (n % 2 == 1) {
        ret *= x;
        ret %= MOD;
      }
      x *= x;
      x %= MOD;
      n >>= 1;
    }
    return ret;
  };
  ;
  for (i64 i = 1; i <= N; i++) {
    prd = p(prd, i);
    prd %= MOD;
  }
  cout << count * prd % MOD << endl;
  return 0;
}
