// Date: Tue, 21 Apr 2026 12:00:01 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  ll ans = 0;
  for (ll i = 0; i < N; i++) ans = A[i] * 2 - ans;
  ans /= 2;
  for (ll i = 0; i < N; i++) {
    cout << ans << " ";
    ans = A[i] * 2 - ans;
  }
  cout << endl;
  return 0;
}
