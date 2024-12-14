// Date: Sat, 14 Dec 2024 12:04:38 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll N, R;
  cin >> N >> R;
  for (ll i = 0; i < N; i++) {
    ll D, A;
    cin >> D >> A;
    if (D == 1) {
      if (1600 <= R && R < 2800) {
        R += A;
      }
    } else {
      if (1200 <= R && R < 2400) {
        R += A;
      }
    }
  }
  cout << R << endl;
  return 0;
}
