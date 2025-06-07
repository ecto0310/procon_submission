// Date: Sat, 07 Jun 2025 12:19:25 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, L;
  cin >> N >> L;
  vector<ll> A(N);
  for (ll i = 1; i < N; i++) {
    cin >> A[i];
  }

  if (L % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }

  for (ll i = 1; i < N; i++) {
    A[i] = (A[i - 1] + A[i]) % L;
  }

  map<ll, ll> count;
  for (ll p : A) {
    count[p]++;
  }

  ll ans = 0;
  for (auto [p1, c] : count) {
    ll p2 = (p1 + L / 3) % L;
    ll p3 = (p2 + L / 3) % L;
    ans += count[p1] * count[p2] * count[p3];
  }

  cout << ans / 3 << endl;
  return 0;
}
