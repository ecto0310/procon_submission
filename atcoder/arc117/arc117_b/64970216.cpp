// Date: Fri, 18 Apr 2025 11:53:50 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll MOD = 1000000000 + 7;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (ll &i : A) {
    cin >> i;
  }
  A.push_back(0);
  sort(A.begin(), A.end());
  ll ans = 1;
  for (ll i = 0; i < N; i++) {
    ans *= (A[i + 1] - A[i] + 1);
    ans %= MOD;
  }
  cout << ans << endl;
  return 0;
}
