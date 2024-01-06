// Date: Sat, 06 Jan 2024 12:02:41 +0000
// Language: C++ 20 (gcc 12.2)
#include <bits/stdc++.h>

using ll = int64_t;
using namespace std;

int main() {
  ll N;
  cin >> N;
  for (ll x = 0; x <= N; x++) {
    for (ll y = 0; y <= N - x; y++) {
      for (ll z = 0; z <= N - x - y; z++) {
        cout << x << " " << y << " " << z << endl;
      }
    }
  }
  return 0;
}
