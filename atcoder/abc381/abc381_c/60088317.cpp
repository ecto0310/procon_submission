// Date: Fri, 22 Nov 2024 13:54:13 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    if (S[i] != '/') {
      continue;
    }
    ll count = 1;
    for (ll t = 1; 0 <= i - t && i + t < N; t++) {
      if (S[i - t] != '1' || S[i + t] != '2') {
        break;
      }
      count += 2;
    }
    ans = max(ans, count);
  }
  cout << ans << endl;
  return 0;
}
