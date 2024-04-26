// Date: Fri, 26 Apr 2024 12:24:17 +0000
// Language: C++ 23 (gcc 12.2)
#include <bits/stdc++.h>

using ll = long long;
using namespace std;

int main() {
  ll a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  if (0 < a) {
    cout << (b - a) * e << endl;
  } else {
    cout << -a * c + d + b * e << endl;
  }
}
