// Date: Sun, 04 Feb 2024 05:33:03 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll &i : A) {
    cin >> i;
  }
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ans += A[i];
    ans = max(0LL, ans);
  }
  cout << ans << endl;
  return 0;
}
