// Date: Fri, 20 Feb 2026 11:17:53 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  vector<string> S(12);
  for (ll i = 0; i < 12; i++) {
    cin >> S[i];
  }
  ll ans = 0;
  for (ll i = 0; i < 12; i++) {
    bool ok = false;
    for (char j : S[i]) {
      if (j == 'r') {
        ok = true;
      }
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
