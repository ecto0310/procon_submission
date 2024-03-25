// Date: Mon, 25 Mar 2024 09:13:51 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> S(N);
  for (ll i = 0; i < N; i++) {
    cin >> S[i];
  }
  set<ll> a;
  for (ll i = 1; i < 1000; i++) {
    for (ll j = 1; j < 1000; j++) {
      a.insert(4 * i * j + 3 * i + 3 * j);
    }
  }
  ll ans = 0;
  for (ll i : S) {
    if (a.count(i) == 0) {
      ans++;
    }
  }
  cout << ans << endl;
}
