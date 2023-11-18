// Date: Sat, 18 Nov 2023 13:51:33 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N;
  string S;
  cin >> N >> S;
  vector<ll> m(26);
  m[S[0] - 'a'] = 1;
  ll count = 1;
  for (ll i = 1; i < N; i++) {
    if (S[i] == S[i - 1]) {
      count++;
      m[S[i] - 'a'] = max(m[S[i] - 'a'], count);
    } else {
      count = 1;
      m[S[i] - 'a'] = max(m[S[i] - 'a'], count);
    }
  }
  ll ans = 0;
  for (ll i : m) {
    ans += i;
  }
  cout << ans << endl;
  return 0;
}
