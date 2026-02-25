// Date: Wed, 25 Feb 2026 11:06:21 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> X(N), Y(N), Z(N);
  for (ll i = 0; i < N; i++) {
    cin >> X[i] >> Y[i] >> Z[i];
  }
  ll z_sum = accumulate(begin(Z), end(Z), 0);
  vector<long long> dp(z_sum + 1, 1e18);
  dp[0] = 0;
  for (ll i = 0; i < N; i++) {
    ll w = max(0LL, (X[i] + Y[i]) / 2 + 1 - X[i]);
    for (ll j = z_sum - Z[i]; j >= 0; j--) {
      dp[j + Z[i]] = min(dp[j + Z[i]], dp[j] + w);
    }
  }
  ll ans = 1e18;
  for (ll j = z_sum / 2 + 1; j <= z_sum; j++) ans = min(ans, dp[j]);
  cout << ans << endl;
  return 0;
}
