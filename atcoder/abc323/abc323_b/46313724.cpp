// Date: Sat, 07 Oct 2023 12:30:14 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

int main() {
  ll N;
  cin >> N;
  vector<string> S(N);
  for (ll i = 0; i < N; i++) {
    cin >> S[i];
  }
  vector<pair<ll, ll>> c(N);
  for (ll i = 0; i < N; i++) {
    ll count = 0;
    for (char j : S[i]) {
      if (j == 'o') {
        count++;
      }
    }
    c[i] = {count, -i};
  }
  sort(c.rbegin(), c.rend());
  for (ll i = 0; i < N; i++) {
    cout << -c[i].second + 1 << " \n"[i + 1 == N];
  }
  return 0;
}
