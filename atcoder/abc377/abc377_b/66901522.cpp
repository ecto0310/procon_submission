// Date: Fri, 20 Jun 2025 11:01:34 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  vector<string> S(8);
  for (auto& i : S) {
    cin >> i;
  }
  ll ans = 0;
  for (ll i = 0; i < 8; i++) {
    for (ll j = 0; j < 8; j++) {
      bool ok = true;
      if (S[i] != string(8, '.')) {
        ok = false;
      }
      for (ll k = 0; k < 8; k++) {
        if (S[k][j] != '.') {
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
