// Date: Fri, 18 Apr 2025 10:41:42 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, D;
  cin >> N >> D;
  vector<ll> T(N);
  for (ll &i : T) {
    cin >> i;
  }
  for (ll i = 0; i < N - 1; i++) {
    if (T[i + 1] - T[i] <= D) {
      cout << T[i + 1] << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
