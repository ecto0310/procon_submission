// Date: Fri, 20 Jun 2025 11:21:42 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  string S;
  cin >> S;
  ll N = S.size();
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    if (S[i] == 'U') {
      ans += i * 2 + N - i - 1;
    } else {
      ans += i + (N - i - 1) * 2;
    }
  }
  cout << ans << endl;
  return 0;
}
