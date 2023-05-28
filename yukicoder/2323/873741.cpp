// Date: Sun, 28 May 2023 13:38:59 +0000
// Language: C++17
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  string A, B;
  cin >> A >> B;
  i64 a_len = A.size(), b_len = B.size();
  reverse(A.begin(), A.end());
  reverse(B.begin(), B.end());
  i64 ans = 0;
  for (i64 i = 0; i < max(a_len, b_len); i++) {
    i64 t = 0;
    if (i < a_len && A[i] == '1') {
      t++;
    }
    if (i < b_len && B[i] == '1') {
      t++;
    }
    if (t == 1) {
      ans += 1 << i;
    }
  }
  cout << ans << endl;
  return 0;
}
