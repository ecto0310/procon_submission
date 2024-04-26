// Date: Fri, 26 Apr 2024 12:14:52 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  for (ll i = 0; i < 3; i++) {
    ll h1, m1, s1, h2, m2, s2;
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    s1 = s1 + m1 * 60 + h1 * 3600;
    s2 = s2 + m2 * 60 + h2 * 3600;
    ll ans = s2 - s1;
    cout << ans / 3600 << " " << (ans % 3600) / 60 << " " << ans % 60 << endl;
  }
}
