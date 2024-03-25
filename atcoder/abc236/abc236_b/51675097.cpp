// Date: Mon, 25 Mar 2024 09:16:44 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N;
  cin >> N;
  map<ll, ll> m;
  for (ll i = 0; i < 4 * N - 1; i++) {
    ll A;
    cin >> A;
    m[A]++;
  }
  for (ll i = 1; i <= N; i++) {
    if (m[i] == 3) {
      cout << i << endl;
    }
  }
}
