// Date: Sat, 30 Dec 2023 07:52:06 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  vector<ll> A(3);
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(), A.end());
  do {
    if (A[2] - A[1] == A[1] - A[0]) {
      cout << "Yes" << endl;
      return 0;
    }
  } while (next_permutation(A.begin(), A.end()));
  cout << "No" << endl;
  return 0;
}
