// Date: Thu, 11 Apr 2024 10:45:28 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  for (ll i = 1; i <= N; i++) {
    if (i % 3 != 0 && i % 5 != 0) {
      ans += i;
    }
  }
  cout << ans << endl;
  return 0;
}
