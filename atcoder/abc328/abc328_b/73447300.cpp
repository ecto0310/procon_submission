// Date: Fri, 20 Feb 2026 11:16:01 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> D(N);
  for (ll i = 0; i < N; i++) {
    cin >> D[i];
  }
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < D[i]; j++) {
      ll m = i + 1;
      ll d = j + 1;
      string t = to_string(m) + to_string(d);
      bool ok = true;
      for (char k : t) {
        if (t[0] != k) {
          ok = false;
        }
      }
      if (ok) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
