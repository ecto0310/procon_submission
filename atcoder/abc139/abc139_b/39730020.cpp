// Date: Tue, 14 Mar 2023 13:37:30 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 A, B;
  cin >> A >> B;
  i64 count = 1;
  for (i64 i = 0;; i++) {
    if (B <= count) {
      cout << i << endl;
      break;
    }
    count += A - 1;
  }
  return 0;
}
