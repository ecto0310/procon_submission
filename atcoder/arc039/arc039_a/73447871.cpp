// Date: Fri, 20 Feb 2026 11:26:29 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  ll ans = stoi(A) - stoi(B);
  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < 10; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      string t = A;
      t[i] = (j + '0');
      ll tt = stoi(t) - stoi(B);
      ans = max(ans, tt);
    }
  }
  for (ll i = 0; i < 3; i++) {
    for (ll j = 0; j < 10; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      string t = B;
      t[i] = (j + '0');
      ll tt = stoi(A) - stoi(t);
      ans = max(ans, tt);
    }
  }
  cout << ans << endl;
  return 0;
}
