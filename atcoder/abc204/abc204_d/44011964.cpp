// Date: Fri, 28 Jul 2023 12:18:11 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

#include <atcoder/dsu>

using namespace std;
using ll = int64_t;

#ifdef LOCAL
#define cerr cerr << "\033[31m"
#define cout cout << "\033[32m"
#define endl "\033[m" << endl
#endif

int main() {
  ll N;
  cin >> N;
  vector<ll> T(N);
  for (ll& Ti : T) {
    cin >> Ti;
  }
  ll sum = 0;
  vector<bool> dp(100'001);
  dp[0] = true;
  for (ll i = 0; i < N; i++) {
    sum += T[i];
    for (ll j = 100'000 - T[i]; 0 <= j; j--) {
      if (dp[j]) {
        dp[j + T[i]] = true;
      }
    }
  }
  ll ans = 100'000;
  for (ll i = 0; i <= 100'000; i++) {
    if (dp[i]) {
      ans = min(ans, max(sum - i, i));
    }
  }
  cout << ans << endl;
  return 0;
}
