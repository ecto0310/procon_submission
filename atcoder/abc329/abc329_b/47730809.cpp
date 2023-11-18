// Date: Sat, 18 Nov 2023 13:48:21 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll &i : A) {
    cin >> i;
  }
  ll m = *max_element(A.begin(), A.end());
  ll ans = 0;
  for (ll i : A) {
    if (i != m) {
      ans = max(ans, i);
    }
  }
  cout << ans << endl;
  return 0;
}
