// Date: Sat, 22 Jul 2023 12:13:52 +0000
// Language: C++ (GCC 9.2.1)
#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;

#ifdef LOCAL
#define cerr cerr << "\033[31m"
#define cout cout << "\033[32m"
#define endl "\033[m" << endl
#endif

int main() {
  ll N, D;
  cin >> N >> D;
  vector<string> S(N);
  for (ll i = 0; i < N; i++) {
    cin >> S[i];
  }
  ll ans = 0, now = 0;
  for (ll i = 0; i < D; i++) {
    bool ok = true;
    for (ll j = 0; j < N; j++) {
      if (S[j][i] == 'x') {
        ok = false;
      }
    }
    if (ok) {
      now++;
      ans = max(ans, now);
    } else {
      now = 0;
    }
  }
  cout << ans << endl;
  return 0;
}
