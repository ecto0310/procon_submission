// Date: Sun, 09 Apr 2023 12:43:11 +0000
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
  i64 A, B;
  cin >> A >> B;
  i64 cnt = 0;
  while (A != B) {
    if (A < B) {
      cnt += B / A;
      B = B % A;
      if (B == 0) {
        B = A;
        cnt--;
      }
    } else if (B < A) {
      cnt += A / B;
      A = A % B;
      if (A == 0) {
        A = B;
        cnt--;
      }
    }
    debug(A);
    debug(B);
  }
  cout << cnt << endl;
  return 0;
}
