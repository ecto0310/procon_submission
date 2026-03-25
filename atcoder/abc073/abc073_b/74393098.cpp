// Date: Wed, 25 Mar 2026 11:40:38 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll l, r;
    cin >> l >> r;
    ans += r - l + 1;
  }
  cout << ans << endl;
  return 0;
}
