// Date: Sat, 21 Dec 2024 12:12:03 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> H(N);

  for (ll &i : H) {
    cin >> i;
  }
  ll ans = 1;
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      bool ok = true;
      ll count = 0;
      ll add = j - i;
      for (ll k = i; k < N; k += add) {
        if (H[i] != H[k]) {
          break;
        }
        count++;
      }
      if (ok) {
        ans = max(ans, count);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
