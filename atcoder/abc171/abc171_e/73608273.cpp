// Date: Wed, 25 Feb 2026 10:52:48 +0000
// Language: C++23 (GCC 15.2.0)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> a(N);
  for (ll i = 0; i < N; i++) {
    cin >> a[i];
  }
  ll sum = 0;
  for (ll i = 0; i < N; i++) {
    sum ^= a[i];
  }
  for (ll i = 0; i < N; i++) {
    cout << (sum ^ a[i]) << " \n"[i + 1 == N];
  }
  return 0;
}
