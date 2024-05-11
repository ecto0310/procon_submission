// Date: Sat, 11 May 2024 12:20:12 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll MOD = 100000000;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll &i : A) {
    cin >> i;
  }
  sort(A.begin(), A.end());
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    sum += A[i];
  }
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ll idx = lower_bound(A.begin(), A.end(), MOD - A[i]) - A.begin();
    idx = max(idx, i + 1);
    sum -= A[i];
    ans += A[i] * (N - i - 1) + sum - MOD * (N - idx);
  }
  cout << ans << endl;
  return 0;
}
