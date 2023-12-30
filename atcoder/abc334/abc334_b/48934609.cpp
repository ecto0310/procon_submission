// Date: Sat, 30 Dec 2023 12:03:25 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll A, M, L, R;
  cin >> A >> M >> L >> R;
  L -= A;
  R -= A;
  auto calc = [](ll x, ll M) -> ll {
    if (0 <= x) {
      return x / M;
    } else {
      return (x + 1) / M - 1;
    }
  };
  cout << calc(R, M) - calc(L - 1, M) << endl;
  return 0;
}
