// Date: Sat, 11 May 2024 12:32:01 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const ll MOD = 998244353;

int main() {
  ll N;
  cin >> N;
  vector<pair<ll, ll>> A(N);
  vector<ll> cnt(11);
  for (auto &i : A) {
    cin >> i.first;
    ll t = i.first;
    while (t) {
      t /= 10;
      i.second++;
    }
    cnt[i.second]++;
  }
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    (ans += A[i].first * i % MOD) %= MOD;
    cnt[A[i].second]--;
    ll p = 1;
    for (ll j = 0; j <= 10; j++) {
      (ans += (A[i].first * cnt[j]) % MOD * p % MOD) %= MOD;
      (p *= 10) %= MOD;
    }
  }
  cout << ans << endl;
  return 0;
}
