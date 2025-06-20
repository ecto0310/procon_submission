// Date: Fri, 20 Jun 2025 11:04:45 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll h, m;
  cin >> h >> m;
  ll time = h * 60 + m;
  for (ll i = 0; i < 60 * 24; i++) {
    ll t = (time + i) % (60 * 24);
    ll hh = t / 60;
    ll mm = t % 60;
    ll h1 = hh / 10, h2 = hh % 10;
    ll m1 = mm / 10, m2 = mm % 10;
    ll ht = h1 * 10 + m1;
    ll mt = h2 * 10 + m2;
    if (0 <= ht && ht < 24 && 0 <= mt && mt < 60) {
      cout << hh << " " << mm << endl;
      break;
    }
  }
  return 0;
}
