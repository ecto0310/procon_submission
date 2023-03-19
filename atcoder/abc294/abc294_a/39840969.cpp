// Date: Sun, 19 Mar 2023 12:01:05 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main() {
  i64 N;
  cin >> N;
  for (i64 i = 0; i < N; i++) {
    i64 A;
    cin >> A;
    if (A % 2 == 0) {
      cout << A << " ";
    }
  }
  cout << endl;
  return 0;
}
