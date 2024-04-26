// Date: Fri, 26 Apr 2024 12:15:53 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll sum;
  cin >> sum;
  for (ll i = 0; i < 9; i++) {
    ll t;
    cin >> t;
    sum -= t;
  }
  cout << sum << endl;
}
