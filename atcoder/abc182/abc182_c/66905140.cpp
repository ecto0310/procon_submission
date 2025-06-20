// Date: Fri, 20 Jun 2025 15:03:04 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string N;
  cin >> N;
  ll sum = 0;
  for (char c : N) {
    sum += c - '0';
  }
  vector<ll> digits;
  for (char c : N) {
    digits.push_back((c - '0') % 3);
  }
  vector<ll> counts(3, 0);
  for (ll d : digits) {
    counts[d]++;
  }
  bool ok = false;
  ll ans = N.size();
  for (ll i = 0; i <= min(counts[1], 5LL); i++) {
    for (ll j = 0; j <= min(counts[2], 5LL); j++) {
      ll t = sum - i * 1 - j * 2;
      if (i + j != N.size() && t % 3 == 0) {
        ok = true;
        ans = min(ans, i + j);
      }
    }
  }
  if (ok) {
    cout << ans << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
