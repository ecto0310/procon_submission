// Date: Sat, 11 May 2024 12:03:44 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  vector<ll> H(N);
  for (ll &i : H) {
    cin >> i;
  }
  for (ll i = 1; i < N; i++) {
    if (H[0] < H[i]) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << -1 << endl;
  return 0;
}
