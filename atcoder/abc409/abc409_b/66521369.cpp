// Date: Sat, 07 Jun 2025 12:11:35 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());

  ll ans = 0;
  for (ll i = 0; i <= N; i++) {
    ll count = 0;
    for (ll j = 0; j < N; j++) {
      if (A[j] >= i) {
        count++;
      }
    }
    if (count >= i) {
      ans = max(ans, i);
    }
  }

  cout << ans << endl;
  return 0;
}
