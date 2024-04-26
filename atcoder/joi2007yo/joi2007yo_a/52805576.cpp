// Date: Fri, 26 Apr 2024 12:11:14 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll A, B;
  for (ll i = 0; i < 4; i++) {
    ll t;
    cin >> t;
    A += t;
  }
  for (ll i = 0; i < 4; i++) {
    ll t;
    cin >> t;
    B += t;
  }
  cout << max(A, B) << endl;
}
