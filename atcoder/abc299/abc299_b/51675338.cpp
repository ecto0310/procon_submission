// Date: Mon, 25 Mar 2024 09:26:41 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, T;
  cin >> N >> T;
  vector<ll> C(N), R(N);
  for (ll i = 0; i < N; i++) {
    cin >> C[i];
  }
  for (ll i = 0; i < N; i++) {
    cin >> R[i];
  }
  ll ans = -1;
  for (ll i = 0; i < N; i++) {
    if (C[i] == T) {
      if (ans == -1) {
        ans = i;
      } else {
        if (R[ans] < R[i]) {
          ans = i;
        }
      }
    }
  }
  if (ans != -1) {
    cout << ans + 1 << endl;
    return 0;
  }
  T = C[0];
  for (ll i = 0; i < N; i++) {
    if (C[i] == T) {
      if (ans == -1) {
        ans = i;
      } else {
        if (R[ans] < R[i]) {
          ans = i;
        }
      }
    }
  }

  cout << ans + 1 << endl;
}
