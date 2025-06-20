// Date: Fri, 20 Jun 2025 10:57:58 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, K;
  string S;
  cin >> N >> K >> S;
  ll ans = 0;
  for (ll i = 0; i < N - K + 1; i++) {
    if (S.substr(i, K) == string(K, 'O')) {
      ans++;
      i += K - 1;
    }
  }
  cout << ans << endl;
  return 0;
}
