// Date: Sat, 20 Jul 2024 14:25:25 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  auto p10 = [](ll p) -> ll {
    ll res = 1;
    for (ll i = 0; i < p; i++) {
      res *= 10;
    }
    return res;
  };
  if (N == 1) {
    cout << 0 << endl;
    return 0;
  }
  N--;
  for (ll i = 1;; i++) {
    ll t = (i + 1) / 2 - 1;
    ll count = 9 * p10(t);
    if (N <= count) {
      string s = to_string(p10(t) + N - 1);
      string sb = s;
      if (i % 2 == 1) {
        sb.pop_back();
      }
      reverse(sb.begin(), sb.end());
      cout << s << sb << endl;
      return 0;
    } else {
      N -= count;
    }
  }
  return 0;
}
