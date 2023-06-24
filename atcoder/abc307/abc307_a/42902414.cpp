// Date: Sat, 24 Jun 2023 12:13:20 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N;
  cin >> N;
  for (i64 i = 0; i < N; i++) {
    i64 sum = 0;
    for (i64 j = 0; j < 7; j++) {
      i64 A;
      cin >> A;
      sum += A;
    }
    cout << sum << " \n"[i + 1 == N];
  }
  return 0;
}
