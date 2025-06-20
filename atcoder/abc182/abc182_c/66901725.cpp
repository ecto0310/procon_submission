// Date: Fri, 20 Jun 2025 11:18:00 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string N;
  cin >> N;
  ll size = N.size();
  ll ans = size;
  for (ll i = 0; i < (1 << size); i++) {
    ll t = 0, cnt = 0;
    for (ll j = 0; j < size; j++)
      if ((i >> j) & 1) {
        t *= 10;
        t += N[j] - '0';
      } else {
        cnt++;
      }
    if (t % 3 == 0) ans = min(ans, cnt);
  }
  if (ans == size)
    cout << -1 << endl;
  else
    cout << ans << endl;
  return 0;
}
