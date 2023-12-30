// Date: Sat, 30 Dec 2023 07:59:42 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll A, B;
  cin >> A >> B;
  auto sum = [](ll num) -> ll {
    ll ans = 0;
    while (0 < num) {
      ans += num % 10;
      num /= 10;
    }
    return ans;
  };
  cout << max(sum(A), sum(B)) << endl;
  return 0;
}
